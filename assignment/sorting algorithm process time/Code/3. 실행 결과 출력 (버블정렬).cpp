#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[100001];
    FILE *in = fopen("/Users/itsc_macbook/Desktop/randomsort.txt", "r"); //random.txt(보통), randomsort.txt(최선/최악)
    
    for(int i = 0; i < 100000; i++)
    {
        fscanf(in, "%d", &arr[i]);
    }
    
    time_t bubble_start = clock();
    for(int i = 0; i < 100000; i++)
    {
        for(int j = 0; j < 100000-1; j++)
        {
            if(arr[j] > arr[j+1]) //> 오름차순
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    time_t bubble_end = clock();
    printf("버블정렬 실행 시간: %.3lf 초", (double)(bubble_end-bubble_start)/CLOCKS_PER_SEC);
    
}

