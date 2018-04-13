#include <stdio.h>
 
int main()
{
    int arr[100], a;
    scanf("%d", &a);
    for(int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    int tmp, j;
    for(int i = 0; i < a; i++)
    {
        tmp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > tmp)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = tmp;
    }
    for(int i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }
}
