#include <stdio.h>

#define NALPHA 26

int main()
{
    int count2[NALPHA][NALPHA];
    int count1[NALPHA];
    double prob[NALPHA][NALPHA];
    int max, min;
    int c, i, j, first, second;

    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < NALPHA; j++) {
            count2[i][j] = 0;
        }
        count1[i] = 0;
    }

    first = second = ' ';
    
    while((c = getchar()) != EOF) {
        /* if ((c-'a') >= 0 && (c-'a') < NALPHA) { */
        /*     count1[c-'a']++; */
        /* } */
        first = second;
        second = c;
        if ((first-'a') >= 0 && (first-'a') < NALPHA && (second-'a') >= 0 && (second-'a') < NALPHA) {
            count2[first-'a'][second-'a']++;
        }
    }

    for (i = 0; i < NALPHA; i++) {
        count1[i] = 0;
        for (j = 0; j < NALPHA; j++) {
            count1[i] += count2[i][j];
        }
    }

    for (i = 0; i < NALPHA; i++) {
        for (j = 0; j < NALPHA; j++) {
            prob[i][j] = (double)count2[i][j] / (double)count1[i];
        }
    }
    
    for (i = 0; i < NALPHA; i++) {
        j = 0;
        while (prob[i][j] == 0) {
            j++;
        }
        max = min = j;
        for (j = 0; j < NALPHA; j++) {
            if (prob[i][j] > prob[i][max]) {
                max = j;
            } else if (prob[i][j] < prob[i][min] && prob[i][j] != 0) {
                min = j;
            }
        }
        printf("[%c]: min = %c (%e), max = %c (%e)\n", 'a'+i, 'a'+min, prob[i][min], 'a'+max, prob[i][max]);
    }
    return 0;
}
            
