/* 宿題１２で指定された動作を行うプログラム */
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

double pie(double x0, int N);

int main()
{
    const double x0 = 0.1;
    int i;

    for (i = 0; i < MAXN; i++){
        printf("N: %2d x:%.20lf\n", i, pie(x0, i));
    }
    return 0;
}

double pie(double x0, int N)
{
    int i;
    
    double x = x0;
    if (x > 1) {
        fprintf(stderr, "1以下の数値を入力してください\n");
    }
    for (i = 0; i < N; i++) {
        if (x <= 0.5) {
            x = 2 * x;
        } else {
            x = 2 - 2*x;
        }
    }
    return x;
}
