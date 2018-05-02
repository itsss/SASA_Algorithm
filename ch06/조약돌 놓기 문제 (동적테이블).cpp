#include <stdio.h>

int n, a[4][1000], dt[5][310];

int max(int a, int b) { return a > b ? a : b; }

int f(int n, int k){ //n번째 열에, k번째 Case에 해당하는 최댓값
    if(dt[k][n]) return dt[k][n]; //dt[k][n], dt[n][k] 아님!!!
    if(n==0) return 0;
    if(k==1) return dt[k][n] = max(f(n-1, 2), f(n-1, 3)) + a[1][n];
    if(k==2) return dt[k][n] = max(f(n-1, 1), max(f(n-1, 3), f(n-1, 4))) + a[2][n];
    if(k==3) return dt[k][n] = max(f(n-1, 1), f(n-1, 2)) + a[3][n];
    else return dt[k][n] = f(n-1, 2) + a[1][n] + a[3][n];
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
    printf("%d", max(f(n, 1), max(f(n,2), max(f(n,3), f(n,4)) ) )); //n번째 1번 케이스, n번째 2번 케이스, n번째 3번 케이스, n번째 4번 케이스 중 최댓값을 출력
}

