#include <iostream>
#define MAX_N 100
#define MAX_M 99

int N, M;
int arr[MAX_N][MAX_N];

using namespace std;

int CheckCol(int x) {
    int cnt = 1, max_cnt = 1;
    for(int t = 0; t < N - 1; t++) {
        // printf("arr[%d][%d]: %d, arr[%d][%d]: %d\n", t, x, arr[t][x], t + 1, x, arr[t + 1][x]);
        if(arr[t][x] == arr[t + 1][x]) {
            cnt++;
            max_cnt = max(max_cnt, cnt);
        } else {
            cnt = 1;
        }
    }
    return max_cnt;
}

int CheckRow(int x) {
    int cnt = 1, max_cnt = 1;
    for(int t = 0; t < N - 1; t++) {
        // printf("arr[%d][%d]: %d, arr[%d][%d]: %d\n", x, t, arr[x][t], x, t + 1, arr[x][t + 1]);
        if(arr[x][t] == arr[x][t + 1]) {
            cnt++;
            max_cnt = max(max_cnt, cnt);
        } else {
            cnt = 1;
        }
    }
    return max_cnt;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int total_cnt = 0;

    // 행 체크
    for(int i = 0; i < N; i++) {
        int row_cnt = CheckRow(i);
        // cout << "row_cnt: " << row_cnt << endl;
        if(row_cnt >= M) total_cnt += 1;
    }

    // 열 체크
    for(int i = 0; i < N; i++) {
        int col_cnt = CheckCol(i);
        // cout << "col_cnt: " << col_cnt << endl;
        if(col_cnt >= M) total_cnt += 1;
    }

    cout << total_cnt << endl;

    return 0;
}
