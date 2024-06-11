extern char Map[505][505];
void flooding(int R, int C, int pr, int pc)
{
    Map[pr][pc]='W';
    if(pr-1>=0 && Map[pr-1][pc]=='H')
    {
        Map[pr-1][pc]=='W';
        flooding(R, C, pr-1, pc);
    }
    if(pr+1<R && Map[pr+1][pc]=='H')
    {
        Map[pr+1][pc]=='W';
        flooding(R, C, pr+1, pc);
    }
    if(pc-1>=0 && Map[pr][pc-1]=='H')
    {
        Map[pr][pc-1]=='W';
        flooding(R, C, pr, pc-1);
    }
    if(pc+1<C && Map[pr][pc+1]=='H')
    {
        Map[pr][pc+1]=='W';
        flooding(R, C, pr, pc+1);
    }
}
