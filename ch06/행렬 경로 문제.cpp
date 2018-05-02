#include <stdio.h>

int n, a[310][310];

int max(int a, int b) { return a < b ? a : b; }
int min(int a, int b) { return a > b ? a : b; }

int f(int i, int j)
{
    if(i == 1 && j == 1) return a[i][j]; //a[1][1] 의 최댓값
    if(i == 1) return f(i, j-1) + a[i][j]; //첫째 행
    if(j == 1) return f(i-1, j) + a[i][j]; //첫째 열
    return max(f(i, j-1), f(i-1, j)) + a[i][j]; //이들 경우가 아니라면
    //return min(f(i, j-1), f(i-1, j)) + a[i][j];
}

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
    printf("%d", f(n,n));
    return 0;
}
