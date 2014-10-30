#include <stdio.h>

int main() 
{
    int n;
    int i;
    long long ans;

    for(n = 0; n <= 20; n++) {
        ans = 1;
        for (i = 1; i <= n; i++){
            ans *= i;
        }
        printf("%2d %lld\n",n, ans);
    }
    return 0;
}
       
