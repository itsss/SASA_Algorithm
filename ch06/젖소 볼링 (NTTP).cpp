#include <stdio.h>

int main()
{
    int arr[500][500] = {0, };
    int a, b;
    scanf("%d", &a);
    
    for(int i = 1; i <= a; i++)
    {
        for(int j = 0; j < i; j++)
        {
            scanf("%d", &arr[i-1][j]);
        }
    }
    
    for(int i = a-2; i >= 0; i--)
    {
        for(int j = 0; j < i+1; j++)
        {
            b = arr[i+1][j];
            if(arr[i+1][j+1] > b) b = arr[i+1][j+1];
            arr[i][j] += b;
        }
    }
    printf("%d", arr[0][0]);
}
