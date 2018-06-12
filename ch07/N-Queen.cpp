#include <stdio.h>
int n, cnt;
bool col[20], dec[30], inc[30];     // 칸, 좌상향대각선, 우상향대각선 퀸 놓기 가능 여부 확인 배열(통칭하여 visited 배열이라 하겠음)

bool check(int r, int c) {          // visited 배열을 확인하여 퀸 놓기 가능 여부 확인
    if(col[c]) return false;
    if(dec[r-c+n]) return false;
    if(inc[r+c]) return false;
    return true;
}

void set(int r, int c) {            // 퀸을 놓았음을 visited 배열에 표시
    col[c] = dec[r-c+n] = inc[r+c] = 1;
}

void reset(int r, int c) {          // 퀸을 거두었음을 visited 배열에 표시
    col[c] = dec[r-c+n] = inc[r+c] = 0;
}

void dfs(int r, int c) {            // r, c 의 위치에 퀸을 놓음
    if(r==n) {                      // r이 n번째 위치라면 n개의 퀸을 모두 놓음
        cnt++;
        return;
    }
    for(int i=1; i<=n; i++) {       // 1~n까지의 칸에 퀸 놓기를 시도함(정점 방문 가능 확인)
        if(check(r+1, i)) {         // 현재 r번째 줄에서 다음의 줄 r+1번째 줄의 i번째 칸에 퀸 놓을 수 있는지를 확인
            set(r+1, i);            // visited 배열에 표시
            dfs(r+1, i);            // r+1, i 위치에 퀸 놓기(DFS탐색)
            reset(r+1, i);          // 다시 돌아옴 == 퀸을 거둠 == visited 배열에 표시
        }
    }
}

int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {       // 1번째 줄의 각 칸에 퀸 놓기를 시도함
        set(1, i);                  // 해당 줄과 칸에 퀸을 놓음 == visited 배열에 표시
        dfs(1, i);                  // 1, i 위치에 퀸 놓기(DFS탐색)
        reset(1, i);                // 퀸을 거둠 == visited 배열에 표시
    }
    printf("%d\n", cnt);
    return 0;
}



//#include <stdio.h>
//int n, cnt;
//bool col[20], dec[30], inc[30];
//
//bool check(int r, int c) {
//    if(col[c]) return false;
//    if(dec[r-c+n]) return false;
//    if(inc[r+c]) return false;
//    return true;
//}
//
//void set(int r, int c) {
//    col[c] = dec[r-c+n] = inc[r+c] = 1;
//}
//
//void reset(int r, int c) {
//    col[c] = dec[r-c+n] = inc[r+c] = 0;
//}
//
//void dfs(int r) {
//    if(r==n+1) {
//        cnt++;
//        return;
//    }
//    for(int i=1; i<=n; i++) {
//        if(check(r, i)) {
//            set(r, i);
//            dfs(r+1);
//            reset(r, i);
//        }
//    }
//}
//
//int main(void) {
//    scanf("%d", &n);
//    dfs(1);
//    printf("%d", cnt);
//    return 0;
//}

