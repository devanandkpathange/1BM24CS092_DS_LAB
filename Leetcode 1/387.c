int firstUniqChar(char* s) {
    
    for(int i=0;i<strlen(s);i++)
    {
        int c=0;
            for(int j=0;j<strlen(s);j++)
            {
                if (j==i)
                continue;
                else if(s[j]==s[i])
                {
                    c=1;
                    break;
                }
            }
        if(c==0)
        {
            return i;
        }
    }
    return -1;
}
