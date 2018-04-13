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

void insertion(int a[], int k) //insertion(a, 1);
{
    if(k < n)
    {
        int now = a[k];
        int i;
        for(i = k-1; i > -1; i--)
        {
            if(a[i] > now) a[i+1] = a[i];
            else break;
        }
        a[i+1] = now;
        insertion(a, k+1); //다음 Data가 삽입됨.
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
    insertion(a, 1);
    prn(a, n);
    
    return 0;
}


