#include <stdio.h>
#include <math.h>

#define NALPHA 26

double entf(double[], int);
double bhadis(double[NALPHA], double[NALPHA]);

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
    /* double ent[NALPHA];                  /\* エントロピー *\/ */
    double bdis[NALPHA][NALPHA];       /* バタチャリア距離 */
    int c, i, j, first, second;
    comb_t max, min;

    /* 'a'と'b'を基準にする */
    max.a = min.a = 0;
    max.b = min.b = 1;

    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < NALPHA; j++) {
            count[i][j] = 0;
        }
        total[i] = 0;
    }

    first = second = ' ';
    
    while((c = getchar()) != EOF) {
        first = second;
        second = c;
        if ((first-'a') >= 0 && (first-'a') < NALPHA && (second-'a') >= 0 && (second-'a') < NALPHA) {
            count[first-'a'][second-'a']++;
        }
    }

    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < NALPHA; j++) {
            total[i] += count[i][j];
        }
    }

    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < NALPHA; j++) {
            prob[i][j] = (double)count[i][j] / (double)total[i];
        }
    }

    /* i > jとなる場合のみ求める */
    for (i = 0; i < NALPHA; i++) {
        for (j = i+1; j < NALPHA; j++) {
            bdis[i][j] = bhadis(prob[i], prob[j]);
        }
    }

    for (i = 0; i < NALPHA; i++) {
        for (j = i+1; j < NALPHA; j++) {
            if (bdis[i][j] > bdis[max.a][max.b]){
                max.a = i;
                max.b = j;
            } else if(bdis[i][j] < bdis[min.a][min.b]) {
                min.a = i;
                min.b = j;
            }
        }
    }

    printf("最も異なる: %c %c %e\n最も似てる: %c %c %e\n", 'a'+max.a, 'a'+max.b, bdis[max.a][max.b], 'a'+min.a, 'a'+min.b, bdis[min.a][min.b]);
    
    return 0;
}
            
double entf(double prob[], int len)
{
    double ent = 0.0;
    int i;
    for (i = 0; i < len; i++) {
        if (prob[i] > 0.0) {
            ent += prob[i]*(-log2(prob[i]));
        } /* prob[i] == 0.0 のとき ent+= 0となるので無視 */
    }
    return ent;
}

double bhadis(double prob1[NALPHA], double prob2[NALPHA]) 
{
    double dis = 0.0;
    int i;
    
    for (i = 0; i < NALPHA; i++) {
        dis += sqrt(prob1[i] * prob2[i]);
    }
    if (dis == 0) {
        dis = 1000;
    } else {
        dis = -log(dis);
    }

    return dis;
}
