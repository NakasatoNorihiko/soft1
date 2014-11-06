#include <stdio.h>

int s_strlen(char *s);

int main()
{
    char string[] = "Hello, world";

    printf("%d\n", s_strlen(string));
    return 0;
}

int s_strlen(char *s)
{
    int len = 0;
    
    while (s[len] != '\0'){
        len++;
    }
    return len;
}
