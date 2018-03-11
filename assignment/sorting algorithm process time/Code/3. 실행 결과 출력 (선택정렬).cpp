#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[100001];
    FILE *in = fopen("/Users/itsc_macbook/Desktop/random.txt", "r"); //random.txt(보통), randomsort.txt(최선/최악)
    
    for(int i = 0; i < 100000; i++)
    {
        fscanf(in, "%d", &arr[i]);
    }
    
    time_t selection_start = clock();
    for(int i = 0; i < 100000-1; i++)
    {
        for(int j = i+1; j < 100000; j++)
        {
            if(arr[i] < arr[j]) //arr[i]>arr[j] 오름차순
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    time_t selection_end = clock();
    printf("선택정렬 실행 시간: %.3lf 초", (double)(selection_end-selection_start)/CLOCKS_PER_SEC);
    //Selection Sort
    
}
