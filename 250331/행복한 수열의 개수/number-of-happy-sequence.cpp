#include <iostream>

#define MAX_N 100

int N, M;
int arr[MAX_N][MAX_N];

using namespace std;

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
        int cnt = 1;
        for(int j = 0; j < N - 1; j++) {
            if(arr[i][j] == arr[i][j + 1]) cnt++;
        }
        if(cnt >= M) total_cnt++;
    }

    // 열 체크
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        for(int j = 0; j < N - 1; j++) {
            if(arr[j][i] == arr[j + 1][i]) cnt++;
        }
        if(cnt >= M) total_cnt++;
    }

    cout << total_cnt << endl;

    return 0;
}

// N * N 행마다 체크, 열마다 체크해서 해당 수열 개수
