void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *str);

void mx_printstr(const char *s) 
{
    for (int i = 0; i < mx_strlen(s); i++) 
    {
        mx_printchar(s[i]);
    }
}
