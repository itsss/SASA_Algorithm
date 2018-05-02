#include <stdio.h>

int n, a[310][310], dt[310][310];

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    dt[1][1] = a[1][1];
    for(int i = 2; i <= n; i++)
    {
        dt[i][1] = dt[i-1][1] + a[i][1];
        dt[1][i] = dt[1][i-1] + a[1][i];
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            dt[i][j] = min(dt[i-1][j], dt[i][j-1]) + a[i][j];
        }
    }
    printf("%d", dt[n][n]);
}
