/*
 1,000,000개 데이터(중복 없음)
 
 in_random.txt
 in_sorted.txt
 
 ---------------
 in_random.txt
 
 a[0] 601996016
 a[2] 326442858
 
 a[999997] 293046890
 a[999999] 540961752
 
 ---------------
 in_sorted.txt
 
 a[0] 186
 a[1] 855
 a[2] 2004
 
 a[388360] 389217610
 a[388361] 389218002
 
 a[999997] 999995340
 a[999998] 999995714
 a[999999] 999996509
 
 */

#include <stdio.h>
#include <time.h>

//FILE *in = fopen("/Users/itsc_macbook/Desktop/test1/test1/in_random.txt", "r");
FILE *in = fopen("/Users/itsc_macbook/Desktop/test1/test1/in_sorted.txt", "r");

int n, x, a[1000000], b[1000000];

void prn_time(time_t start, time_t end) {
    printf(" %.3lf(sec)\n", (double)(end-start)/CLOCKS_PER_SEC);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int p, int r)
{
    int i = p-1;
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


int select(int a[], int p, int r)
{
    int q = partition(a, p, r);
    if(x == q) return a[q];
    if(x < q) return select(a, p, q-1);
    else return select(a, q+1, r);
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


int main(void)
{
    time_t start, end;
    printf("n: ");
    scanf("%d", &n); //데이터의 개수 n
    for (int i=0; i<n; i++)
    {
        fscanf(in, "%d", a+i);
        b[i] = a[i];
    }
    
    printf("x: ");
    scanf("%d", &x); //몇번째로 작은 데이터를 뽑을지 입력
    x--;
    
    
    //////// 배열 a를 이용한 탐색
    printf("select start\n");
    start = clock();
    int result = select(a, 0, n-1);
    end = clock();
    printf(" data: %d\n", result);
    prn_time(start, end);
    printf("select end\n\n\n");
    
    //////// 배열 b를 이용한 quickSort
    printf("quickSort start\n");
    start = clock();
    quickSort(b, 0, n-1);
    end = clock();
    printf(" data: %d\n", b[x]);
    prn_time(start, end);
    printf("quickSort end\n\n\n");
    
    return 0;
}
