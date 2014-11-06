#include <stdio.h>
#include <stdlib.h>

int s_strlen(char *s);
void s_strcpy(char *s, char *t);

int main()
{
    char string[] = "Hello, world";
    char *str;

    str = (char *)malloc(sizeof(char) * s_strlen(string));
    
    s_strcpy(string, str);
    printf("%s\n", str);

    free(str);

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

void s_strcpy(char *s, char *t)
{
    int i = 0;
    while(*(s+i) != '\0') {
        *(t+i) = *(s+i);
        i++;
    }
    *(t+i) = '\0';

    return;
}
