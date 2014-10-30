#include <stdio.h>
#define MAX 1000

int main()
{
    int n;
    for (n = 1; n <= MAX; n++) {
        if (n % 3 == 0 || n % 10 == 3) {
            printf("%d!!!\n", n);
        } else {
            printf("%d\n", n);
        }
    }

    return 0;
}
        
