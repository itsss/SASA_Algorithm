#include <stdio.h>

int arr[100001];

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int a[], int k, int n) //힙성질을 만족하도록, 자식 Node의 값을 비교해 부모 노드보다 자식 Node가 작다면(최소힙), 바꾸어주고 자식 Node에서 다시 Heapify하는 함수. (단, 조건을 만족하지 않는 경우, 아무 일도 일어나지 않음.)
{
    int left = 2*k, right = 2*k+1, small;
    if(right <= n) small = a[left] < a[right] ? left : right; //자식 노드가 2개인 경우
    else if(left <= n) small = left; //자식 노드가 1개인가?
    else return; //자식 Node가 존재하지 않음.
    
    if(a[k] > a[small])
    {
        swap(&a[k], &a[small]);
        heapify(a, small, n); //작은 Node부터 다시 시작
    }
}

void buildHeap(int a[], int n)
{
    for(int i = n / 2; i > 0; i--) heapify(a, i, n); //자식 Node가 있는 Node를 heapify
}

void heapSort(int a[], int n)
{
    buildHeap(a, n); //주어진 배열을 최소 힙으로 만든다.
    for(int i = n; i > 0; i--) //최소힙 생성후 힙정렬을 수행한다.
    {
        printf("%d\n", a[1]);
        swap(&a[1], &a[i]);
        heapify(a, 1, i-1);
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    for(int i = 1; i <= a; i++) scanf("%d", &arr[i]);
    heapSort(arr, a);
}
// 힙 정렬 (최소 힙)

