#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
int main(void)
{
    int N;
    int stair[305] = {}, DT[305] = {};
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &stair[i]);
    }
    
    for(int i = 1; i <= 3 && i <= N; i++)
    {
        if (i != 3) DT[i] = DT[i - 1] + stair[i];
        else DT[i] = max(stair[i] + DT[i - 2], stair[i] + stair[i - 1]);
    }
    for(int i = 4; i <= N; i++)
    {
        DT[i]=max(stair[i] + DT[i - 2], stair[i] + stair[i - 1] + DT[i - 3]);
    }
    printf("%d\n", DT[N]);
}
