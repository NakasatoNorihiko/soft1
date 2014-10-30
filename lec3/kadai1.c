#include <stdio.h>
#define MAXLEN 25
#define KAIBUN 1
#define NOKAIBUN 0

int main() 
{
    char word[MAXLEN];
    int i,c, len, state;
    state = KAIBUN;
    
    i = 0;
    while((c = getchar()) != EOF && c != '\0' && c != '\n') {
        word[i] = c;
        i++;
    }
    word[i] = '\0';
    len = i;
    for (i = 0; i < len / 2; i++) {
        if (word[i] != word[len-i-1]) {
            state = NOKAIBUN;
            break;
        }
    }
    if (state == KAIBUN) {
        printf("回文です。\n");
    } else {
        printf("回文ではありません。\n");
    }
    
    return 0;
}
