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
    
    int tmp, j;
    time_t insert_start = clock();
    for(int i = 0; i < 100000; i++)
    {
        tmp = arr[i];
        j = i-1;
        while(j>=0 && arr[j] < tmp) //arr[j] > tmp (>) 오름차순
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = tmp;
    }
    time_t insert_end = clock();
    printf("삽입정렬 실행 시간: %.3lf 초", (double)(insert_end-insert_start)/CLOCKS_PER_SEC);
    
}

