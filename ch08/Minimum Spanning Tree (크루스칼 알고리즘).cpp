#include <stdio.h>
#define INF 987654321
#define MAX 20

int n, m, min_cost, cost[MAX][MAX], span[MAX][MAX];

int parent[MAX];

int find(int i) //상위 정점 찾기
{
    while(parent[i]) i = parent[i];
    return i;
}

int uni(int i, int j)  // 싸이클 확인
{
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskal() {
    int a=1, b=1, u=1, v=1, edges = 1, min = INF;
    
    while(edges < n) { // 모든 정점을 방문할 때까지
        min = INF;
        for(int i=1; i<=n; i++) {   // 가장 작은 가중치 간선 찾기
            for(int j=1; j<i; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        
        if(uni(u, v)) {   // 가장 작은 가중치 간선이 싸이클을 발생시키지 않는 경우에
            span[u][v] = span[v][u] = min;
            edges++;
            min_cost += min;
        }
        cost[a][b] = cost[b][a] = INF;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cost[i][j] = INF;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b, v;
        scanf("%d %d %d", &a, &b, &v);
        cost[a][b] = cost[b][a] = v;
    }
    kruskal();
    printf("%d", min_cost);
}
