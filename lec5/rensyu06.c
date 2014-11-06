#include <stdio.h>

int strcmp(char *s, char *t);

int main()
{
    char str1[] = "hello, world";
    char str2[] = "eeic";

    printf("%d\n", strcmp(str1, str2));

    return 0;
}

int strcmp(char *s, char *t)
{
    int i = 0;

    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }
    return s[i] - t[i];
    
    /* while (*(s+i) != '\0' && *(t+i) != '\0') { */
    /*     if (*(s+i) != *(t+i)) { */
    /*         return (*(s+i) - *(t+i)); */
    /*     } */
    /*     i++; */
    /* } */
    /* if (*(s+i) == '\0') { */
    /*     return 1; */
    /* } else if (*(t+i) == '\0') { */
    /*     return -2; */
    /* } else { */
    /*     return 0; */
    /* } */
}
