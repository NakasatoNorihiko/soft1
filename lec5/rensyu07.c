#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void s_qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);

int main()
{
    int nlines;
    char *lineptr[MAXLINES];    /* 文字列を指すポインタの配列 */
    char errmsg[] = "error: input too big to sort"; /* 行数が多すぎる場合のエラーメッセージ */
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) { /* 行数が多すぎなければ */
        s_qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {                    /* 行数が多すぎたらエラーをはいて終了 */
        printf("%s\n", errmsg);
        return 1;
    }
}

/* readlines: 引数 文字列を指し示すポインタの配列, 読み込める最大行数 */
/* 返り値 読み込んだ行数 */
int readlines(char *lineptr[], int maxlines)
{
    int nlines = 0;
    char tmp[MAXLEN];           /* 一時的に文字列を入れる配列 */
    int len;
    
    while(1) {
        len = 0;
        fflush(stdin);          /* 標準出力のストリームを吐き出す */
        if (fgets(tmp, MAXLEN, stdin) == NULL) { /* ヌルポインタにあたるまでブログラムを止めない */
            return nlines;
        } else if (nlines >= maxlines) { /* 行数が多すぎる場合は-1を返す */
            return -1;
        }
        
        while (tmp[len] != '\n') { /* \nを探す */
            len++;
        }
        tmp[len] = '\0'; /* 探した改行記号をつぶす lenは結果的に文字列の長さを示している*/
        lineptr[nlines] = (char *)malloc(sizeof(char) * (len+1)); /* 来たる行を入れるための配列を確保 */
        strcpy(lineptr[nlines], tmp);
        nlines++;
    }
}

/* *lineptr[] 出力したい文字列へのポインタの配列, nlines 行数 */
void writelines(char *lineptr[], int nlines) 
{
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
    return;
}

/* qsort: v[left] ... v[right]をクイックソートする */
/* 再帰を使用している */
void s_qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right) {        /* leftがrightと一致(=配列の要素が1)の時は */
        return;                 /* 何もせずに終了 */
    }
    swap(v, left, (left+right)/2); /* 一番左と真ん中を交換 */
    last = left;
    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            last++;
            swap(v, last, i);
        }
    }
    swap(v, left, last);
    s_qsort(v, left, last-1);
    s_qsort(v, last+1, right);
}

/* 文字列を示すポインタの配列を交換 */
void swap(char *v[], int i, int j) 
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
