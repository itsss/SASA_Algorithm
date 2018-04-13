#include <stdio.h>

int arr[100001];

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int p, int r)
{
    int j;
    int x = a[r]; //기준 원소
    int i = p-1; //i는 1구역의 끝지점
    
    for(j = p; j <= r-1; j++) //j는 3구역의 시작 지점
    {
        if(a[j] <= x)
        {
            swap(&a[++i], &a[j]); //i값 증가 후 a[i]<->a[j] 교환
        }
    }
    swap(&a[i+1], &a[j]); //기준원소와 2구역 첫원소 교환
    return i+1;
}
//배열 A[p ... r]의 원소들을 A[r]을 기준으로 양쪽으로 재배치, A[r] 이 자리한 위치를 리턴함.

void quickSort(int a[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(a, p, r); //분할
        quickSort(a, p, q-1); //왼쪽 부분 배열 정렬
        quickSort(a, q+1, r); //오른쪽 부분 배열 정렬
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    for(int i = 0; i < a; i++) scanf("%d", &arr[i]);
    quickSort(arr, 0, a-1);
    for(int i = 0; i < a; i++) printf("%d\n", arr[i]);
}
// 퀵 정렬 (기준원소 a[r]

