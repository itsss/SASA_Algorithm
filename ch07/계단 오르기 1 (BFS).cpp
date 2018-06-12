#include <stdio.h>
#include <queue>

int n, cnt;
void bfs(int s)
{
    std::queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        if(now >= n) {
            if(now == n) cnt++;
            continue;
        }
//        if(now == n) {
//            cnt++;
//            continue;
//        }
//        if(now > n) continue;
        q.push(now + 1);
        q.push(now + 2);
    }
}

int main() {
    scanf("%d", &n);
    bfs(0);
    printf("%d", cnt);
}
