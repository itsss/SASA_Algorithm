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
    int piv = a[r]; //pivot(기준)
    int i=p-1, j; //i : 기준보다 작은 데이터의 끝 location, j : 기준보다 큰 데이터의 끝 location
    
    for(j = p; j <= r-1; j++) //기준을 제외한 p~r-1까지 비교
    {
        if(a[j] <= piv) //만약, 기준 데이터보다 arr[j] 가 크다면
        {
            swap(&a[++i], &a[j]); //인덱스 i를 증가시킨 (++i) 위치와 arr[j] swap.
        }
    }
    swap(&a[i+1], &a[j]); //정렬이 완료되면, 기준보다 작은 Data, 큰 Data 사이에 기준 Data를 옮겨준다. 기준보다 큰 첫번째 Data(i+1)를 옮기면 되므로, swap(&arr[i+1], &arr[j]) 로 swap해준다.
    return i+1; //이후, 기준원소의 위치인 i+1을 반환한다. 이 함수가 파티션 함수이다.
}

void quickSort(int a[], int p, int r)
{
    int q;
    if(p < r) //입력 데이터가 2개 이상인지 확인한다.
    {
        q = partition(a, p, r);
        quickSort(a, p, q-1); //p~q-1 정렬
        quickSort(a, q+1, r); //q+1~r 정렬
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    
    for(int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, a-1);
    for(int i = 0; i < a; i++)
    {
        printf("%d\n", arr[i]);
    }
}

