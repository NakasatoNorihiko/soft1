#include <stdio.h>

int main()
{
    int **p;
    int *s;
    int a[3][2];
    int i, j;

    p = &s;
    s = a[0];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            a[i][j] = 2*i + j;
        }
    }

    printf("%d %d %d %d\n", **p, **(p+1), *(s+1), a[2][1]);
    printf("%d %d %d %d\n", **a, **(a+1), *(*a+1), *(*(a+2)+1));
    return 0;
}

    
