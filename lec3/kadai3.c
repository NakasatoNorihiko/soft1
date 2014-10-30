/* 指針 */
/* 1. 2以外の素数は奇数のため、調べる対象を3以上の奇数とする(2は最初に素数としておく) */
/* 2. 検査数の上限をnの平方根までに限定 */
/* 3. 検査数を見つかった素数に限定 */
/* 1.だけ使うと余りを求める回数は498501->249001に減少する。これは調べるべき対象が約半分になったため。 */
/* 次に2.を用いると10482に減少する。検査数はおおよそで1.のときのnの平方根の逆数倍にであるから、n=100で10%,n=1000で3.1%程度。そのため減少率は1.に比べて大きくなったと考えられる。*/
/* 最後に3.を用いると2359に減少する。 */

#include <stdio.h>
#define MAX 100000
#define PRIME 1
#define NOPRIME 0

int main() 
{
    int i, j, n, count, np;     /* countは余りを計算した回数をだすカウンター、npは素数の数 */
    int prime[MAX];             /* prime[i]はi+1が素数かどうかを表す */
    int state;
    int maxsearch;  /* 最大の検査数 */

    count = 0;
    for ( i = 0; i < MAX; i++) {
        prime[i] = NOPRIME;
    }
    prime[0] = 2; /* 最小の素数は2 */
    np = 1;

    for (n = 3; n <= MAX; n += 2) { /* 3から2ずつ増えていく=3以上の奇数をループする */
        i = 0;
        maxsearch = 1;
        state = PRIME;

        /* 検査をnの平方根まで限定するために、最大検査数*最大検査数 >= nとなるような最小の最大検査数を探す */
        while(maxsearch*maxsearch < n) {
            maxsearch++;
        }

        /* 素数のリストがつきた(=初期値0に達した)場合と素数が最大検査数を超えた場合はループを抜ける */
        while (prime[i] != 0 && prime[i] <= maxsearch) {
            count++;            /* 次のifで余りを探すのでカウンターを+1 */
            /* 割り切れてしまった場合は素数でないので、状態をNOPRIMEにしループを抜ける */
            if ((n % prime[i]) == 0){ 
                state = NOPRIME;
                break;
            }
            i++;
        }
        if (state == PRIME) {
            prime[np] = n;
            np++;
        }
    }

    i = 0;
    /* while (prime[i] != 0) { */
    /*     printf("%d ", prime[i]); */
    /*     i++; */
    /* } */
    printf("\n%d\n", count);

    return 0;
}
