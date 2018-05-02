#include <stdio.h>

int dt[100001];

int f(int k)
{
    if(dt[k]) return dt[k]; //값이 있는가?
    dt[k] = f(k-2) + f(k-1);
    return dt[k];
}

int main()
{
    int a;
    scanf("%d", &a);
    dt[1] = dt[2] = 1;
    printf("%d", f(a));
}
