#include <stdio.h>

int a[10000000], n;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int k, int n)
{
    int left = 2*k, right = 2*k+1, big; //small => big
    
    if(right <= n) big = a[left] > a[right] ? left : right;
    else if(left <= n) big = left;
    else return;
    
    if(a[k] < a[big])
    {
        swap(&a[k], &a[big]);
        heapify(a, big, n);
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
        //printf("%d ", a[1]);
        swap(&a[1], &a[i]);
        heapify(a, 1, i-1);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i+1]);
    }
    heapSort(a, n);
}


