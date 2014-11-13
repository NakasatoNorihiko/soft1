/* 宿題１,２で指定された動作を行うプログラム */
/* 誤差の影響を小さくする改良をしている */
/* 浮動小数点を用いているために誤差が生じるので、与えられた数を10^9倍して、int型にしてから計算する。10^9倍をするのは、int型が32bitで 2147483647(=2.1*10^9)まで表現できるため*/
/* 小数点10桁目以降は捨てられている。 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100

int pie(int x0, int N);
int f2i(double x);

int main()
{
    const double x0 = 0.1;
    const int xint = f2i(x0);
    int i;

    for (i = 0; i <= MAXN; i++){
        printf("N: %3d x:%.9lf\n", i, (double)(pie(xint, i))/1000000000);
    }
    return 0;
}

int pie(int x0, int N)
{
    int i;
    
    int x = x0;

    for (i = 0; i < N; i++) {
        if (x <= f2i(0.5)) {
            x = 2 * x;
        } else {
            x = f2i(2.0) - 2*x;
        }
    }
    return x;
}

/* double型のxを10^9倍のint型に変換して返す */
/* xの誤差は小数点以下9位までには及んでいないとする */
int f2i(double x)
{
    int ret;
    ret = (int) (x * pow(10, 9));
    return ret;
}

