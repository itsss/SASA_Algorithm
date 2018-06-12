#include <stdio.h>

int cnt, n;

void dfs(int k) {
    if(k==n) { //목적지에 도달했다면?
        cnt++; //카운트 증가
        return;
    }
    if(k>n) return; //3번째 계단에 가야하는데 2->4번째 계단 간 경우
    dfs(k+1); //그렇지 않은 경우 현재 계단에서 1계단 올라가기
    dfs(k+2); //그렇지 않은 경우 현재 계단에서 2계단 올라가기
}

int main() {
    scanf("%d", &n);
    dfs(0); //0번 정점부터 방문 시작
    printf("%d", cnt);
}
