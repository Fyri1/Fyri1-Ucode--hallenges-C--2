#include <stdio.h>

void mx_printchar(char c);
void mx_printint(int n);

void mx_printint(int n) 
{
    if (n < 0) 
    {
        mx_printchar('-');
        n = n*(-1);
    }
    if (n ==0)
    {
         mx_printchar('0');
         return;
    }
    int flag = 0;

    if (n ==-2147483648)
    {
    
        n /= 10;
        n = n*(-1);
        flag=1;
    }
    
     int temp = n, num_len = 0;
    for (int i = 0; temp != 0; i++) {
        temp /= 10;
        num_len++;
    }
    char arr[num_len];
    
    for (int i = 0; n != 0; i++) 
    {
        arr[i] = (char)((n % 10) + 48);
        n /= 10; 
    }

    for (int i = num_len-1; i >= 0; i--) 
    {
        mx_printchar(arr[i]);
    }

    if (flag == 1)
    {
        mx_printchar('8');
    }
}

