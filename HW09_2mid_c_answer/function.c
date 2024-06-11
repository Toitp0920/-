extern char Map[505][505];
void flooding(int R, int C, int pr, int pc)
{
    if (Map[pr][pc]=='H') {
        Map[pr][pc] = 'W';
        if (pr+1<R) flooding(R,C,pr+1,pc);
        if (pr-1>=0) flooding(R,C,pr-1,pc);
        if (pc+1<C) flooding(R,C,pr,pc+1);
        if (pc-1>=0) flooding(R,C,pr,pc-1);
    }
}
