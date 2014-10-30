#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    float fahr, celsius;

    fahr = LOWER; //float にint に代入
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("fahr = %3.0f\tcelsius = %6.1f\n", fahr, celsius);
        fahr += STEP;
    }
    return 0;
}


