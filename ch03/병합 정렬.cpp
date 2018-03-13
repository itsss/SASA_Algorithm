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

void merge(int a[], int p, int q, int r)
{
/*    int i = p, j = q+1, k = p;
    int tmp[100000];
    while(i<=q && j<=r)
    {
        if(a[i]<=a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i<=q) tmp[k++] = a[i++];
    while (j<=r) tmp[k++] = a[j++];
    for(int i = p; i <= r; i++)
    {
        a[i] = tmp[i];
    }*/
    int i=p, j=q+1, temp[1000000], t=0;
    while(i <= q && j <= r)
    {
        if(a[i] < a[j]) temp[t++] = a[i++];
        else temp[t++] = a[j++];
    }
    while(i <= q) temp[t++] = a[i++];
    while(j <= r) temp[t++] = a[j++];
    i=p;
    t=0;
    while(i <= r) a[i++] = temp[t++];
}

void mergeSort(int a[], int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2; //p, r의 중간 지점 계산
        mergeSort(a, p, q); //전반부 정렬
        mergeSort(a, q+1, r); //후반부 정렬
        merge(a, p, q, r); //병합
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n-1);
    prn(a, n);
}
// 1452: 데이터 정렬 (large)
