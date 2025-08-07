#include <iostream>
#include <algorithm>

#define MAX 200

using namespace std;

// 상우, 상좌, 하우, 하좌
pair<int, int> dir[4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int N, M;
int arr[MAX][MAX];

bool InRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // 첫 번째 블록
    int cnt1 = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int t = 0; t < 4; t++) {
                if(InRange(i + dir[t].first, j) && InRange(i, j + dir[t].second)) {
                    int num1 = arr[i][j];
                    int num2 = arr[i + dir[t].first][j];
                    int num3 = arr[i][j + dir[t].second];

                    int sum = num1 + num2 + num3;
                    cnt1 = max(sum, cnt1);
                }
            }
        }
    }


    // 두 번째 블록
    int cnt2 = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 행
            if(InRange(i, j + 1) && InRange(i, j + 2)) {
                int num1 = arr[i][j];
                int num2 = arr[i][j + 1];
                int num3 = arr[i][j + 2];

                int sum = num1 + num2 + num3;
                cnt2 = max(sum, cnt2);
            }

            // 열
            if(InRange(i + 1, j) && InRange(i + 2, j)) {
                int num1 = arr[i][j];
                int num2 = arr[i + 1][j];
                int num3 = arr[i + 2][j];

                int sum = num1 + num2 + num3;
                cnt2 = max(sum, cnt2);
            }
        }
    }

    int max_sum = max(cnt1, cnt2);

    cout << max_sum << endl;
    
    return 0;
} 

// N * M -> 블럭 놓아서 합 최대
// 회전, 뒤집기 가능
// (1) 가운데 잡고 상우, 상좌, 하우, 하좌
// (2) 행/열 3개 연속