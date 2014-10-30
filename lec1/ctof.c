#include <stdio.h>

#define LOWER 0 //表の下限
#define UPPER 300 //表の上限
#define STEP 20 //ステップサイズ

int main()
{
    float fahr, celsius;

    fahr = LOWER;
    
    printf("fahr\tcelsius\n");
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += STEP;
    }

    return 0;
}
