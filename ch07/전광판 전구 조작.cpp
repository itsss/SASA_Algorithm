#include <stdio.h>

int m, n, cnt, cnt1;
int a[110][110], b[110][110];

void dfs(int x, int y){
    a[x][y] = 1;
    if(x>1 && a[x-1][y]==0) dfs(x-1, y);
    if(x<m && a[x+1][y]==0) dfs(x+1, y);
    if(y>1 && a[x][y-1]==0) dfs(x, y-1);
    if(y<n && a[x][y+1]==0) dfs(x, y+1);
}

void dfs1(int x, int y){
    b[x][y] = 0;
    if(x>1 && b[x-1][y]==1) dfs1(x-1, y);
    if(x<m && b[x+1][y]==1) dfs1(x+1, y);
    if(y>1 && b[x][y-1]==1) dfs1(x, y-1);
    if(y<n && b[x][y+1]==1) dfs1(x, y+1);
}

int main(void) {
    scanf("%d %d", &m, &n);
    for(int i=1; i<=m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            a[i][j] = tmp;
            b[i][j] = tmp;
        }
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j]==0) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(b[i][j]==1) {
                cnt1++;
                dfs1(i, j);
            }
        }
    }
    printf("%d %d", cnt, cnt1);
}

