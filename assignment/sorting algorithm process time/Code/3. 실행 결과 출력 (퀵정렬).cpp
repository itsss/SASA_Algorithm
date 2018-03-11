#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;


void quick_sort(int *arr, int left, int right)
{
    int i, j;
    int temp;
    int pivot = arr[left];
    if(left < right)
    {
        i = left;
        j = right+1;
        while( i <= j)
        {
            do
                i++;
            while(arr[i] < pivot); //< 오름차순
            
            do
                j--;
            while(arr[j] > pivot); //> 오름차순
            if(i<j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else break;
        }
        temp = arr[j];
        arr[j] = arr[left];
        arr[left] = temp;
        
        quick_sort(arr, left, j-1);
        quick_sort(arr, j+1, right);
    }
}

int main()
{
    int arr[100001];
    FILE *in = fopen("/Users/itsc_macbook/Desktop/randomsort.txt", "r"); //random.txt(보통), randomsort.txt(최선/최악)
    
    for(int i = 0; i < 100000; i++)
    {
        fscanf(in, "%d", &arr[i]);
    }
    
    time_t quick_start = clock();
    quick_sort(arr, 0, 100000);
    time_t quick_end = clock();
    printf("퀵정렬 실행 시간: %.3lf 초", (double)(quick_end-quick_start)/CLOCKS_PER_SEC);
    
}

