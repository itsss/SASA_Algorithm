#include <stdio.h>

int f(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;
    else return f(n-1) + f(n-2);
}

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", f(a));
}
