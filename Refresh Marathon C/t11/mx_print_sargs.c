int mx_strcmp(const char *s1, const char *s2);
void mx_printstr(const char *str);
void mx_printchar(char c);
int mx_strlen(const char *s);

int main(int argc, char *argv[]  ) 
{
   int flag;

    if(argc < 2) 
        return 0;
    

    flag = 1;
    int i = 1;

    while (flag == 1) {
        flag = 0;

        for(; i < argc - 1; i++) {
            if(mx_strcmp(argv[i], argv[i + 1]) > 0) {
                char* tmp = argv[i];
                argv[i] = argv[i + 1];
                argv[i + 1] = tmp;
                flag = 1;
            }  
        }
        
        i = 1;
    }

    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printchar('\n');
    }

    return 0;
    

}

