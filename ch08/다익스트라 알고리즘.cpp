#include <stdio.h>
#define MAX 100
#define INF 987654321

int n, m, G[MAX][MAX], visited[MAX], dist[MAX];

void dijkstra() {
    int min_dist, v;
    
    dist[1] = 0;
    for(int i = 1; i <= n; i++) {
        min_dist = INF;
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && min_dist > dist[j]) {
                min_dist = dist[j];
                v = j;
            }
        }
        
        visited[v] = 1;
        for(int j = 1; j <= n; j++) {
            if(dist[j] > dist[v] + G[v][j])
                dist[j] = dist[v] + G[v][j];
        }
    }
}

int main() {
    int a, b, w;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) G[i][j] = INF;
        }
    } //모든 정점들간의 거리를 무한대로 만듬
    
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        G[a][b] = G[b][a] = w;
    }
    
    for(int i = 1; i <= n; i++) dist[i] = INF;
    
    dijkstra();
    
    printf("%d", dist[n]);
    
    return 0;
}
