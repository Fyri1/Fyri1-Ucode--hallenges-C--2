char *mx_strcpy(char *dst, const char *src);

char *mx_strcpy(char *dst, const char *src)
{
    int lenas = 0;
    while(src[lenas] != '\0') 
    {
        lenas++;
    }

    for (int i = 0; src[i] && i < lenas; i++) 
    {
        dst[i] = src[i];
    }
    dst[lenas] = '\0';

    return dst;
}



