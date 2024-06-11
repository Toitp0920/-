/*
qsort:
http://www.gnu.org/software/libc/manual/html_node/Array-Sort-Function.html#Array-Sort-Function

使用 qsort
void qsort (void *array, size_t count, size_t size, comparison_fn_t compare);

參考 Week 14 補充

fgets
http://www.cplusplus.com/reference/cstdio/fgets/
*/

/*
利用 qsort() 將資料以不同原則重新排列

(a) 依照電影名稱的英文字母順序
(b) 依照上映年份排序，從早期到近期，如果年份相同，則再依照電影名稱的英文字母順序排序
(c) 依照平均評分的高低排序，由高到低，如果評分相同，則再依照參與評分的網友數量排序

將 (a) (b) (c) 的排序結果 分別輸出為 sort1.txt, sort2.txt, sort3.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    double rating;
    char name[64];
    int year;
    int reviews;
} Movie;

Movie movies[300];

int cmp1(const void *a, const void *b) //(a) 依照電影名稱的英文字母順序
{
    /*
    要 return 的狀況有三種
    a > b => 1
    a < b => -1
    a = b => 0
    因此return type應為int
    */
    /*
    字串排序比較
    strcmp("abc", "abd")
    => abc < abd 此時
    會return一「負數」
    */
    Movie *s, *t;
    s = (Movie*) a; //把void *a 轉換成Movie * a
    t = (Movie*) b; //把void *b 轉換成Movie * b
    return strcmp(s->name, t->name); //等同 (*s).name, (*t).name
    //如果要由大排到小：
    //return -strcmp(s->name, t->name);
}
int cmp2(const void *a, const void *b) //(b) 1.依照上映年份排序，2.再依照電影名稱的英文字母
{
    Movie *s, *t;
    s = (Movie*) a;
    t = (Movie*) b;
    if (s->year > t->year) return 1;
    else if (s->year < t->year)
        return -1;
    else
        return strcmp(s->name, t->name);
}
int cmp3(const void *a, const void *b) //(c) 依照平均評分，再依照參與評分的網友數量排序
{
    Movie *s, *t;
    s = (Movie*) a;
    t = (Movie*) b;
    if (s->rating > t->rating) return -1;
    else if (s->rating < t->rating) return 1;
    else
    {
        if (s->reviews > t->reviews) return -1;
        else if (s->reviews < t->reviews) return 1;
        else return 0;
    }
}

void write(char * fname, Movie *mvs, int NM)
{
    int i;
    FILE *fout;
    fout = fopen(fname, "w");
    for (i=0; i<NM; i++)
    {
        fprintf(fout, "%3d: %f\t%s\t(%d)\t%d\n", i+1, mvs[i].rating, mvs[i].name, mvs[i].year, mvs[i].reviews);
    }
    fclose(fout);
}

int main(void)
{
    int NM;
    FILE *fin;

    char line[255];
    fin = fopen("imdb_top250.txt", "r");

    NM = 0;
    while (!feof(fin))
    {
        //1.處理電影評分
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].rating = atof(line); //atof()是ASCII to float(浮點數，不是float型別)，把讀到的字串資料改成double資料
        //2.處理電影名字
        if (fgets(line, 255, fin)==NULL) break;
        line[strlen(line)-1] = '\0'; //因為第 ( strlen(line)-1 )個字元是'\n'，我們要把它改成'\0'
        strcpy(movies[NM].name, line); //把line[]裡面的內容存進movies array裡面的Movie資料結構裡面的name[]array裡面
        //3.處理電影年分
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].year = atoi(line); //atoi()是ASCII to int，年份都是整數
        //4.處理電影票房
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].reviews = atoi(line);
        NM++;
        if (fgets(line, 255, fin)==NULL) break; //這句主要是因為每筆資料之間都有空一行，所以多讀一行，把那行讀掉之後，再從下一個資料開始loop
    }
    fclose(fin);
    /*
    這個很重要，每次fgets讀取資料時，設fclose才是完整的流程。
    因為如果程式繼續打開那個檔案，那同時別的程式就沒辦法開啟、寫入、修改那個檔案
    ，所以用完之後馬上要關
    */

    /*
        for (i=0; i<NM; i++) {
            printf("%3d: %f\t%s\t(%d)\t%d\n",
                   i+1, movies[i].rating, movies[i].name, movies[i].year, movies[i].reviews);
        }
    */

    //void qsort (array指標「開頭位置」, 資料數量, array資料大小, 排序邏輯);
    qsort(movies, NM, sizeof(Movie), cmp1);
    write("sort1.txt", movies, NM);

    qsort(movies, NM, sizeof(Movie), cmp2);
    write("sort2.txt", movies, NM);

    qsort(movies, NM, sizeof(Movie), cmp3);
    write("sort3.txt", movies, NM);

    return 0;
}
