#include <stdio.h>
int main()
{
    int sum,i;
    sum = 0;
    for(i = 1; i<=10; i++) {
        sum += i;
        printf("%d\n",sum);
    }
}
