/* アトキンのふるいの実装 */
/* 余りは12で割ったもの */
/* すべてのx,yは正の数 */
/* ふるいに入っていくのは次の規則に従う */
/*     1. 2,3,5の結果リストを作成 */
/*     2. すべての正の数が入ってるリストを作成(最初はすべて非素数と仮定されている) */
/*     3. n=4x^2+y^2としてnの余りが1,5になるか調べる */
/*        n=3x^2+y^2では7 */
/*        n=3x^2 - y^2 (x>y)では11になるか調べる */
/*     4. ふるいリストの小さい数字から開始 */
/*     5. 次の数字をとり、結果リストに追加 */
/*     6. それを平方してその整数倍は素数でない */
/*     7. 5.6を/* 繰り返す *\/ */
/* MAX=100000のときkadai3.c(探索対象を奇数+ */



#include <stdio.h>
#define MAX 100000
#define PRIME 1
#define NOPRIME 0

int flip(int);

int main() 
{
    int result[MAX]; /* result[i]がi+1が素数かを示す */
    int sqrmax = 1;
    int i, j, x, y,z, n;
    int count = 0;
    
    while(sqrmax * sqrmax < MAX) {
        sqrmax++;
    }
    
    for(i = 0; i < MAX; i++) {
        result[i] = NOPRIME;
    }
    result[2-1] = result[3-1] = result[5-1] = PRIME;

    /* for (z = 1; z <= 5; z += 4) { */
    /*     for (y = z; y < sqrmax; y += 6) { */
    /*         for (x = 1; x <= sqrmax && (n = 4*x*x + y*y) <= MAX; x++) { */
    /*             result[n-1] = flip(result[n-1]); */
    /*         } */
    /*         for (x = y+1; x <= sqrmax && (n = 3*x*x - y*y) <= MAX; x += 2) { */
    /*             result[n-1] = flip(result[n-1]); */
    /*         } */
    /*     } */
    /* } */
        
    /* for (z = 2; z <= 4; z += 2) { */
    /*     for (y = z; y <= sqrmax; y += 6) { */
    /*         for (x = 1; x <= sqrmax && (n = 3*x*x + y*y) <= MAX; x += 2) { */
    /*             result[n-1] = flip(result[n-1]); */
    /*         } */
    /*         for (x = y + 1; x <= sqrmax && (n = 3*x*x - y*y) <= MAX; x += 2) { */
    /*             result[n-1] = flip(result[n-1]); */
    /*         } */
    /*     } */
    /* } */

    /* for (y = 3; y <= sqrmax; y += 6) { */
    /*     for (z = 1 ; z <= 2; z++) { */
    /*         for (x = z; x <= sqrmax && (n = 4*x*x + y*y) <= MAX; x += 3) { */
    /*             result[n-1] = flip(result[n-1]); */
    /*         } */
    /*     } */
    /* } */
    
                
    for (x = 1; x <= sqrmax; x++) {
        for (y = 1; y <= sqrmax; y++) {
            n = 4*x*x + y*y;
            count += 2;
            if (n <= MAX && (n % 12 == 1 || n % 12 == 5)) {
                result[n-1] = flip(result[n-1]);
                
            }
            
            n = 3*x*x + y*y;
            count++;
            if (n <= MAX && n % 12 == 7) {
                result[n-1] = flip(result[n-1]);
            }

            n = 3*x*x-y*y;
            count++;
            if (x > y && n <= MAX && n % 12 == 11) {
                result[n-1] = flip(result[n-1]);
            }
        }
    }
    
    for (n = 5; n <= sqrmax; n++) {
        if (result[n-1] == PRIME) {
            for (j = n*n; j <= MAX; j += n*n) {
                result[j-1] = NOPRIME;
            }
        }
    }

    /* MAXが大きいのでコメントアウト */
    /* for (i = 0; i < MAX; i++) { */
    /*     if (result[i] == PRIME) { */
    /*         printf("%d ", i+1); */
    /*     } */
    /* } */
    printf("\n%d\n", count);

    return 0;
}

int flip(int result) 
{
    if (result == PRIME) {
        return NOPRIME;
    } else {
        return PRIME;
    }
}

    
