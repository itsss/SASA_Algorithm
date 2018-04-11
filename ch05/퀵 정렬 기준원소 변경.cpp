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

int partition(int a[], int p, int r)
{
    int j;
    int x = a[p]; // a[r] => a[p] 기준점 이동
    int i = p; //p-1 => p Code 수정
    for (j = p+1; j <= r; j++) //j=p -> j=p+1, j <= r-1 -> j <= r Code 수정
    {
        if (a[j] <= x) swap(&a[++i], &a[j]);
    }
    swap(&a[i], &a[r]); //a[i+1] => a[i] Code 수정
    return i; //return i+1 => return i Code 수정
}


void quickSort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
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
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
//pivot 위치 맨 앞으로 변경
