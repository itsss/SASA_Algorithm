#include <stdio.h>
#include <queue>

int n, k, cnt;
void bfs(int s)
{
    std::queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        if(now == n) {
            cnt++;
            continue;
        }
        if(now > n || now == k) continue;
        q.push(now + 1);
        q.push(now + 2);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    bfs(0);
    printf("%d", cnt);
}
