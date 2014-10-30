#include <stdio.h>
#include <math.h>

#define NALPHA 26

double bhadis(double[NALPHA], double[NALPHA]);

/* バタチャリア距離が最大最小になる組み合わせを保存する構造体 */
typedef struct 
{
    int a;
    int b;
} comb_t;

int main()
{
    int count[NALPHA][NALPHA];  /* abが出てきた回数->count[0][1] */
    int total[NALPHA];          /* aが一文字目に出てきた->total[0] */
    double prob[NALPHA][NALPHA]; /* 確率 */
    double bdis[NALPHA][NALPHA];       /* バタチャリア距離 */
    int c, i, j, first, second;
    comb_t max, min;

    /* 'a'と'b'を基準にする */
    max.a = min.a = 0;
    max.b = min.b = 1;

    /* 回数を初期化する */
    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < NALPHA; j++) {
            count[i][j] = 0;
        }
        total[i] = 0;
    }

    /* 文字を一時的に保存するための変数を初期化 */
    first = second = ' ';
    
    while((c = getchar()) != EOF) {
        /* 新しい文字が入ってきたので1文字ずらす */
        first = second;
        second = c;
        /* 両方ともaからzに入っているとき */
        if ((first-'a') >= 0 && (first-'a') < NALPHA && (second-'a') >= 0 && (second-'a') < NALPHA) {
            count[first-'a'][second-'a']++;
        }
    }

    /* 'a'+iが1文字目になった回数を記録 */
    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < NALPHA; j++) {
            total[i] += count[i][j];
        }
    }

    /* 1文字目がiのとき,2文字目にjが出てくる条件付き確率 */
    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < NALPHA; j++) {
            prob[i][j] = (double)count[i][j] / (double)total[i];
        }
    }

    /* バタチャリア距離はiとjで対称、かつi=jのときは当然0になる(=考えなくてよい)ので、i < jとなる場合のみ求める */
    for (i = 0; i < NALPHA; i++) {
        for (j = i+1; j < NALPHA; j++) {
            bdis[i][j] = bhadis(prob[i], prob[j]);
        }
    }

    /* バタチャリア距離が最小・最大になる文字の組を求める。 */
    for (i = 0; i < NALPHA; i++) {
        for (j = i+1; j < NALPHA; j++) { /* i < jとなる場合しかバタチャリア距離を求めていないので、 i >= jにならないようにする*/
            if (bdis[i][j] > bdis[max.a][max.b]){
                max.a = i;
                max.b = j;
            } else if(bdis[i][j] < bdis[min.a][min.b]) {
                min.a = i;
                min.b = j;
            }
        }
    }

    printf("Maximum Distance: %c %c %e\nMinimum Distance: %c %c %e\n", 'a'+max.a, 'a'+max.b, bdis[max.a][max.b], 'a'+min.a, 'a'+min.b, bdis[min.a][min.b]);
    
    return 0;
}

double bhadis(double prob1[NALPHA], double prob2[NALPHA]) 
{
    double dis = 0.0;
    int i;
    
    for (i = 0; i < NALPHA; i++) {
        dis += sqrt(prob1[i] * prob2[i]);
    }
    dis = -log(dis);

    return dis;
}
