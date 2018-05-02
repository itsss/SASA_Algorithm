#include <stdio.h>

char a[1010], b[1010];
int al, bl, dt[1001][1001]; //DT Table에 0 넣지 말것

int max(int a, int b) { return a > b ? a : b; }

int f(int x, int y)
{
    if(x == -1 || y == -1) return 0;
    if(dt[x][y]) return dt[x][y];
    if(a[x] == b[y]) return dt[x][y] = f(x-1, y-1) + 1;
    else return dt[x][y] = max(f(x-1, y), f(x, y-1));
}

int main(){
    scanf("%s", a);
    scanf("%s", b);

    while(a[++al]);
    while(b[++bl]);

//    for(int i = 0; i < al+1; i++)
//    {
//        for(int j = 0; j < bl+1; j++)
//        {
//            dt[i][j] = -1;
//        }
//    }
    printf("%d", f(al-1, bl-1));
}

