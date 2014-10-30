#include <stdio.h>
#include <math.h>

#define NALPHA 26

double entf(double[], int);
double bhadis(double[NALPHA], double[NALPHA]);

int main()
{
    int count[NALPHA][NALPHA];  /* abが出てきた回数->count[0][1] */
    int total[NALPHA];          /* aが一文字目に出てきた->total[0] */
    double prob[NALPHA][NALPHA]; /* 確率 */
    double ent[NALPHA];                  /* エントロピー */
    double bdis[NALPHA][NALPHA];       /* バタチャリア距離 */
    int c, i, j, first, second;

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

    for (i = 0; i < NALPHA; i++) {
        for (j = i; j < NALPHA; j++) {
            bdis[i][j] = bhadis(bdis[i], bdis[j]);
        }
    }
    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < i; j++) {
            bdis[i][j] = bdis[j][i];
        }
    }
    

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
    dis = log(dis);

    return dis;
}
