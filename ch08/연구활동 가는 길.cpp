#include <stdio.h>
#define MAX 100
#define INF 987654321

int n, m, min, G[MAX][MAX], visited[MAX];

void dfs(int k, int dist) {
    visited[k] = 1;
    //if(dist >= min) return; //경험적 배제
    if(k == n) {
        if(min > dist) min = dist;
        return;
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i] && G[k][i]) {
            dfs(i, dist+G[k][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    int a, b, w;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        G[a][b] = G[b][a] = w;
    }
    min = INF;
    dfs(1,0);
    if(min!=INF) printf("%d", min);
    else printf("Impossible");
    return 0;
}

