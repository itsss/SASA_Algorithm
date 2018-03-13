#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10000000], n;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void prn(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    puts("");
}

int partition(int a[], int p, int r)
{
    int i=p-1;
    int pivot = a[r];
    for(int j = p; j < r; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return i+1;
}

void quickSort(int a[], int p, int r)
{
    if(p < r)
    {
        int q = partition(a, p, r); //기준의 위치를 partition 함수가 반환
        quickSort(a, p, q-1); //앞을 기준으로 Quick Sort (p~q-1)
        quickSort(a, q+1, r); //q+1 ~ r
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n-1);
    prn(a, n);
}
// 1452: 데이터 정렬 (large)
