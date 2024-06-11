int isPalindrome (char *start, char *end)
{
    int i;
    int pal=0;
    for (i = 0; i<strlen(start); i++)
    {
        if ( *(start + i) == *(end - i) ) pal++ ;
        else break;
    }
    if (pal == strlen (start)) return 1;
    else return 0;
}
