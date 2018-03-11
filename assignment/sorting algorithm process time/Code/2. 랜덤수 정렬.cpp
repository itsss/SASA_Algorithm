#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[100001];
    FILE *in = fopen("/Users/itsc_macbook/Desktop/random.txt", "r");
    FILE *out = fopen("/Users/itsc_macbook/Desktop/randomsort.txt", "w");
    int a;
    scanf("%d", &a);
    for(int i = 0; i < a; i++)
    {
        fscanf(in, "%d", &arr[i]);
    }
    sort(arr, arr+a);
    for(int i = 0; i < a; i++)
    {
        fprintf(out, "%d\n", arr[i]);
    }
}
