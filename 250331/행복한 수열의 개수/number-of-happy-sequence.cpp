#include <iostream>

#define MAX_N 100
#define MAX_M 99

int N, M;
int arr[MAX_N][MAX_N];

using namespace std;

int CheckCol(int x) {
    int cnt = 1;
    for(int t = 0; t < N - 1; t++) {
        if(arr[t][x] == arr[t + 1][x]) cnt++;
        else cnt = 1;
    }
    return cnt;
}

int CheckRow(int x) {
    int cnt = 1;
    for(int t = 0; t < N - 1; t++) {
        if(arr[x][t] == arr[x][t + 1]) cnt++;
        else cnt = 1;
    }
    return cnt;
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
    int row_cnt = 0;
    for(int i = 0; i < N; i++) {
        int row_cnt = CheckRow(i);
        if(row_cnt >= M) total_cnt += 1;
    }

    // cout << "==================" << endl;

    // 열 체크
    for(int i = 0; i < N; i++) {
        int col_cnt = CheckCol(i);
        if(col_cnt >= M) total_cnt += 1;
    }

    cout << total_cnt << endl;

    return 0;
}

// N * N 행마다 체크, 열마다 체크해서 해당 수열 개수

