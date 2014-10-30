#include <stdio.h>
#define MAX 1000
#define PRIME 1
#define NOPRIME 0

int main() 
{
    int i, j, count;
    int state;

    count = 0;
    for ( i = 2; i <= MAX; i++) {
        state = PRIME;
        for ( j = 2; j < i; j++) {
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
    
