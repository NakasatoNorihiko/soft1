#include <stdio.h>

int main()
{
    int *ip, *sump;
    int i, sum;

    sump = &sum;
    ip = &i;

    for (*ip = 0; *ip <= 10; (*ip)++) {
        *sump += *ip;
    }
    printf("sum = %d\n", *sump);
    return 0;
}

