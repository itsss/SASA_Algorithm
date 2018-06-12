#include <stdio.h>
int n, m, a[101][101];

int main(void) {
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = a[y][x] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%2d", a[i][j]);
        }
        puts("");
    }
}

/*
 6 8
 1 2
 1 3
 1 4
 1 6
 2 3
 3 5
 4 6
 5 6
 */
