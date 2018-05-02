#include <stdio.h>

int dt[100001];

int main()
{
    int a;
    scanf("%d", &a);
    dt[1] = dt[2] = 1;
    for(int i = 3; i <= a; i++)
        dt[i] = dt[i-2] + dt[i-1];
    printf("%d", dt[a]);
    return 0;
}

//동적테이블 처음부터 채워나가기: 피보나치 수열
