#include <iostream>
using namespace std;

int arr[100 + 1][100 + 1];
int N, M, Q, r;
char d;
bool dir; // left == 0, right == 1

void doLeft(int cur) { // 오른쪽으로 이동 시킴
    int temp = arr[cur][M];
    for (int i = M; i >= 2; i--) {
        arr[cur][i] = arr[cur][i - 1];
    }
    arr[cur][1] = temp;
}

void doRight(int cur) { // 왼쪽으로 이동 시킴
    int temp = arr[cur][1];
    for(int i = 1; i < M; i++) {
        arr[cur][i] = arr[cur][i + 1];
    }
    arr[cur][M] = temp;
}

void doMove(bool dir, int cur) {
    // cout << "dir: " << dir << ", cur: " << cur << endl;
    if(!dir) doLeft(cur);
    else doRight(cur);
}

bool shouldContinueUp(int target) {
    if(target - 1 == 0) return false;
    for(int i = 1; i <= M; i++) {
        if(arr[target - 1][i] == arr[target][i]) return true;
    }
    return false;
}

bool shouldContinueDown(int target) {
    if(target + 1 == N + 1) return false;
    for(int i = 1; i <= M; i++) {
        if(arr[target + 1][i] == arr[target][i]) return true;
    }
    return false;
}

int main() {
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> r >> d;
    if(d == 'L') dir = 0;
    else dir = 1;

    int start_r = r;
    int start_dir = dir;
    // Q번 진행
    while(Q--) {
        // 최초 바람
        if(!start_dir) {
            doLeft(start_r);

            // 전파 체크
            int cur = start_r;
            while(shouldContinueUp(cur)) {
                cur--;
                dir = !dir;
                doMove(dir, cur);
            }

            cur = start_r;
            dir = start_dir;
            while(shouldContinueDown(cur)) {
                cur++;
                dir = !dir;
                doMove(dir, cur);
            }
        }
        else {
            doRight(start_r);

            // 전파 체크
            int cur = start_r;
            dir = !dir;
            while(shouldContinueUp(cur)) {
                cur--;
                doMove(dir, cur);
            }
            cur = start_r;
            dir = start_dir;
            while(shouldContinueDown(cur)) {
                cur++;
                dir = !dir;
                doMove(dir, cur);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// N * M, Q번
// 위 아래로... 이때 같은 숫자 있는지 체크 -> true면 반대 방향으로 밀림 while.
// 전파될 때마다 반대 방향
// r = 전파시작 행, d = 방향(L, R)