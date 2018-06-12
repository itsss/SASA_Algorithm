#include <stdio.h>
#include <queue>

int n, m, G[101][101];
int visited[101];
std::queue<int> q;

void bfs(int k) {
    visited[k] = 1;
    printf("%d ", k);
    q.push(k);
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        for(int i=1; i<=n; i++) {
            if(G[v][i] && !visited[i]) {
                q.push(i);
                printf("%d ", i);
                visited[i] = 1;
            }
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
    bfs(1);
}
