#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[100000];

int main()
{
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    
    int n;
    scanf("%d", &n);
    srand((int)time(NULL));
    for(int i = 0; i < n; i++)
    {
        fscanf(in, "%d", &arr[i]);
    }
    
    time_t s = clock();
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    time_t e = clock();
    for(int i = 0; i < n; i++)
    {
        fprintf(out, "%d\n", arr[i]);
    }
    printf("\n실행 시간 %.3lf초\n", (double)(e-s)/CLOCKS_PER_SEC); //실행 시간 계산
}
