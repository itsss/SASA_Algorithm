#include <stdio.h>
#include <queue>

typedef struct { int now, pw; }st;

int n, cnt;
std::queue<st> q;

void bfs(st s) {
    q.push(s);
    while(!q.empty()) {
        st v = q.front(); q.pop();
        if(v.now == n) {
            cnt++;
            continue;
        }
        if(v.now > n) continue;
        q.push({v.now+1, v.pw+1});
        q.push({v.now+2, v.pw+1});
        if(v.pw > 1) q.push({v.now+3, 0});
    }
}

int main() {
    scanf("%d", &n);
    bfs({0,2});
    printf("%d", cnt);
}
