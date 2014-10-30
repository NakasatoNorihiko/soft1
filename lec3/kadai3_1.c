#include <stdio.h>
#define MAX 1000
#define PRIME 1
#define NOPRIME 0

int main() 
{
    int i, j, count;
    int state, maxsearch;

    printf("2 ");               /* 2は素数なのでprintする */
    count = 0;
    for ( i = 3; i <= MAX; i += 2) {
        state = PRIME;
        maxsearch = 1;
        while(maxsearch*maxsearch < i) {
            maxsearch++;
        }

        for ( j = 2; j <= maxsearch; j++) {
            if ((i % j) == 0) {
                state = NOPRIME;
            }
            count++;
        }
        if (state == PRIME) {
            printf("%d ", i);
        }
    }
    printf("\n%d\n", count);
    
    return 0;
}
    
