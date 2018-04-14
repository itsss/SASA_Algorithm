#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[1000000], n;
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
        printf("%d ", a[i]);
    }
    puts("");
}

void selection(int a[], int k)
{
    if(k>0) //검사할 요소가 있는가? (마지막 요소의 인덱스가 0보다 클 때)
    {
        for(int i = 0; i < k; i++)
        {
            if(a[i] > a[k])
            {
                swap(&a[i], &a[k]);
            }
        }
        selection(a, k-1);
    }
}

int main()
{
    srand((int)time(NULL));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        a[i] = rand()%100;
    }
    prn(a, n);
    selection(a, n-1);
    prn(a, n);
    
    return 0;
}
