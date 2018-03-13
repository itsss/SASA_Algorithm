#include <stdio.h>

int a[10000000], n;

void prn(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    puts("");
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int k, int n)
{
    int left = 2 * k;
    int right = 2 * k + 1;
    int small;
    
    if(right<=n) small = a[left] < a[right] ? left : right;
    else if(left<=n) small = left;
    else return;
    
    if(a[k]>a[small])
    {
        swap(&a[k], &a[small]);
        heapify(a, small, n);
    }
}


void buildHeap(int a[], int n)
{
    for(int i=n/2; i>0; i--)
    {
        heapify(a, i, n);
    }
}


void heapSort(int a[], int n)
{
    buildHeap(a, n);
    for(int i=n; i>0; i--)
    {
        printf("%d ", a[1]);
        swap(&a[1], &a[i]);
        heapify(a, 1, i-1);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i+1]);
    }
    prn(a+1, n);
    heapSort(a, n);
}
