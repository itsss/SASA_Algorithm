#include <stdio.h>
#include <queue>
int n, cnt;
std::queue<int> q;

void dfs(int now, int power) {
    if(now > n) return;
    if(now == n) {
        cnt++;
        return;
    }
    dfs(now+1, power+1);
    dfs(now+2, power+1);
    if(power>1) dfs(now+3, 0);
}

int main() {
    scanf("%d", &n);
    dfs(0, 2);
    printf("%d", cnt);
}
