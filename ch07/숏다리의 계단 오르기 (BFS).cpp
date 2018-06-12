#include <stdio.h>
#include <queue>
int n, cnt;
std::queue<int> qnow;
std::queue<int> qpower;//2개의 Queue를 이용하여 구현

void bfs(int now, int power) {
    qnow.push(now);
    qpower.push(power);
    while(!qnow.empty()) {
        int vnow = qnow.front(); qnow.pop();
        int vpower = qpower.front(); qpower.pop();
        if(vnow == n) {
            cnt++;
            continue;
        }
        if(vnow > n) continue;
        qnow.push(vnow+1); qpower.push(vpower+1);
        qnow.push(vnow+2); qpower.push(vpower+1);
        if(vpower > 1) { //힘이 남아 있음을 의미
            qnow.push(vnow+3); qpower.push(0);
        }
    }
}

int main() {
    scanf("%d", &n);
    bfs(0, 2);
    printf("%d", cnt);
}

