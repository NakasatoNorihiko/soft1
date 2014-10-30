#include <stdio.h>

#define FIRST 1
#define NOFIRST 0

int main()
{
    int nc,c, state;
    state = FIRST;

    while((c = getchar()) != EOF){
        if (state == FIRST) {
            putchar(c);
        }
        if (c == ' ') {
            state = NOFIRST;
        } else if (c == '\n') {
            state = FIRST;
            putchar(c);
        }
    }
    return 0;
}

           

/* int main() */
/* { */
/*     int c, nl ,nw, nc, state; */
    
/*     state = OUT; */
/*     nl = nw = nc = 0; */
    
/*     while((c = getchar()) != EOF){ */
/*         ++nc; */
/*         if (c == '\n'){ */
/*             ++nl; */
/*         } */
/*         if (c == ' ' || c == '\n' || c == '\t') { */
/*             state = OUT; */
/*         } else if (state == OUT) { */
/*             state = IN; */
/*             ++nw; */
/*         } */
/*     } */
/*     printf("%d %d %d\n", nl,nw,nc); */
/*     return 0; */
/* } */

