#include <stdio.h>
int n, m, G[101][101];
int visited[101]; //k번 정점 방문 여부를 저장, 0(기본값, 방문하지 않았다로 정의)

void dfs(int k) {
    visited[k] = 1;
    printf("%d ", k);
    for(int i=1; i<=n; i++) {
        if(!visited[i] && G[k][i]){
            //printf("%d - %d\n", k, i); //순회하는 간선 정보 출력
            dfs(i);
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x][y] = G[y][x] = 1;
    }
    dfs(1); //k번 정점부터 방문 시작!
    //dfs(6): 6 1 2 3 4 5 8 7
    //dfs(8): 8 1 2 3 4 5 6 7
    //dfs(1): 1 2 3 4 5 6 7 8
}

/*
8 11
1 2
1 6
1 8
2 3
2 5
2 6
3 4
3 5
4 5
6 7
6 8
 */
