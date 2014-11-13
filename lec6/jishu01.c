#include <stdio.h>

void increment(void);

int main()
{
    int i;
    for (i = 0; i < 3; i++) {
        increment();
    }
    return 0;
}

void increment() 
{
    int a = 0;
    static int b = 0;
    a++;
    b++;
    printf("a:%d, b:%d\n", a, b);
}
