#include <stdio.h>

int n, a[3][300];

int max(int a, int b) { return a > b ? a : b; }

int f(int n, int k){
    if(n==0) return 0;
    if(k==1) return max(f(n-1, 2), f(n-1, 3)) + a[1][n];
    if(k==2) return max(f(n-1, 1), max(f(n-1, 3), f(n-1, 4))) + a[2][n];
    if(k==3) return max(f(n-1, 1), f(n-1, 2)) + a[3][n];
    if(k==4) return f(n-1, 2) + a[1][n] + a[3][n];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d", max(f(n, 1), max(f(n,2), max(f(n,3), f(n,4)) ) ));
}
