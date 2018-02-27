#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int i, j, n, t;
    scanf("%d", &t);
    
    while(t-- > 0)
    {
        scanf("%d", &n);
        int arr1[2][100001], arr2[2][100001];
        for(i = 0; i <= 1; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &arr2[i][j]);
            }
        }
        arr1[0][0] = arr1[1][0] = 0;
        arr1[0][1] = arr2[0][1];
        arr1[1][1] = arr2[1][1];
        for(i = 2; i <= n; i++)
        {
            arr1[0][i] = max(arr1[1][i-1], arr1[1][i-2]) + arr2[0][i];
            arr1[1][i] = max(arr1[0][i-1], arr1[0][i-2]) + arr2[1][i];
        }
        printf("%d\n", max(arr1[0][n], arr1[1][n]));
    }
}
