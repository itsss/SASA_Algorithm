#include <stdio.h>
#define INF 987654321
#define MAX 20

int n, m, min_cost, cost[MAX][MAX], span[MAX][MAX];

void prim()
{
    int visited[MAX] = {0}, a=1, b=1, u=1, v=1, edges = 1, min = INF;
    
    visited[1] = 1;
    while(edges < n)
    {
        min = INF;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i])
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        
        if(!visited[v]) {
            edges++;
            span[u][v] = span[v][u] = min;
            min_cost += min;
            visited[b] = 1;
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
    prim();
    printf("%d", min_cost);
}

