#include <stdio.h>

int n, a[310][310], dt[310][310];

int min(int a, int b) { return a < b ? a : b; }

int f(int i, int j)
{
    if(dt[i][j]) return dt[i][j];
    if(i == 1 && j == 1) return a[i][j];
    if(i == 1) return dt[i][j] = f(i, j-1) + a[i][j]; //첫째 행
    if(j == 1) return dt[i][j] = f(i-1, j) + a[i][j]; //첫째 열
    return dt[i][j] = min(f(i, j-1), f(i-1, j)) + a[i][j]; //이들 경우가 아니라면
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
    //dt[1][1] = a[1][1];
    printf("%d", f(n,n));
    return 0;
}
//격자판의 최소합: 메모이제이션 + 가장 낮은 점수 구하기
