#include <stdio.h>
#include <math.h>

#define NALPHA 26

double entf(double[], int);

int main()
{
    double prob[NALPHA];
    double ent;
    int count[NALPHA];
    int c, i, total;

    total = 0;
    ent = 0.0;
    for (i = 0; i < NALPHA; i++) {
        count[i] = 0;
    }
    
    while((c = getchar()) != EOF) {
        if ((c-'a') >= 0 && (c-'a') < NALPHA) {
            count[c-'a']++;
        }
    }

    for (i = 0; i < NALPHA; i++) {
        total += count[i];
    }
    for (i = 0; i < NALPHA; i++) {
        prob[i] = (double)count[i] / total;
        ent = entf(prob, NALPHA);
    }

    printf("entropy = %e\n",ent);

    return 0;
}

double entf(double prob[], int len)
{
    double ent = 0.0;
    int i;
    for (i = 0; i < len; i++) {
        if (prob[i] > 0.0) {
            ent += prob[i]*(-log2(prob[i]));
        }
    }
    return ent;
}

