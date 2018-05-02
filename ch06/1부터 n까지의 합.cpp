#include <stdio.h>

int f(int n)
{
    if(n==0) return n;
    else return f(n-1)+n;
}

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", f(a));
}

//재귀함수: 1부터 n까지의 합
