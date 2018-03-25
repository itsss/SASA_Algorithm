#include <stdio.h>

int n, arr[100001];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        arr[k]++;
    }
    for(int i = 0; i < 100001; i++)
    {
        while(arr[i]--)
        {
            printf("%d ", i);
        }
    }
    return 0;
}

// 계수정렬
