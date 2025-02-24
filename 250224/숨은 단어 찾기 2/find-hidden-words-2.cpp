#include <iostream>

#define DIR_NUM 8

using namespace std;

// 상하좌우대각선
int dx[DIR_NUM] = {1,-1, 0, 0, 1, -1, 1, -1};
int dy[DIR_NUM] = {0, 0, -1, 1, -1, 1, 1, -1};

int N, M;
char arr[50][50];

bool InRange(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

int main() { 
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int dir = 0; dir < DIR_NUM; dir++) {
                int nx = i, ny = j;
                
                bool found = true;
                string target = "LEE";
                for (int k = 0; k < 3; k++) {
                    if (!InRange(nx, ny) || arr[nx][ny] != target[k]) {
                        found = false;
                        break;
                    }
                    nx += dx[dir];
                    ny += dy[dir];
                }
                
                if (found) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}