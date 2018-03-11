#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int arr[100000], arr2[100000];

int main()
{
    int n;
    scanf("%d", &n);
    srand((int)time(NULL));
    for(int i = 0; i < n; i++)
    {
        arr[i] = arr2[i] = (rand()%100);
    }
    
    //Selection Sort
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
        printf("%d ", arr[i]);
    }
    printf("\nSelection Sort : %.3lf초\n", (double)(e-s)/CLOCKS_PER_SEC); //실행 시간 계산
    
    //Quick Sort
    time_t sq = clock();
    sort(arr2, arr2+n);
    time_t eq = clock();
    printf("Quick Sort : %.3lf초\n", (double)(eq-sq)/CLOCKS_PER_SEC);
}

