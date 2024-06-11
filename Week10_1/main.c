/*寫出一個求開平方根的function
以下是演算法：
求A
A*A=x
此時有個z*z>x
則 x / z 一定>A
得到 z > A > x/z
意思就是A介於z跟x/z之間(這兩個的平均數)
此時就可以用新的z重新逼近一次
令z=( z + x/z )/2
遞迴
*/

#include <stdio.h>
double sqrt0(double x, double z);
int main()
{
        printf("%.12f\n",  sqrt0(3, 1.5));
        return 0;
}
double abs0(double y)
{
        return (y>0) ? y : -y;
        //學起來！ 「? y : -y」這個寫法的意思是
        //if(y>0) 則return y
        //else return -y
}

double sqrt0(double x, double z)
{
        if(abs0(z*z-x)<0.000001) return z;
        else
                return sqrt0(x, 0.5*(z+x/z));
}
//這種return自己的寫法(譬如輾轉相除法也是)
//叫做tail recursion
//這種recursion可以被compiler做最佳化
//也就是不再保留最初的參數，只保留新的參數，因為答案相同
