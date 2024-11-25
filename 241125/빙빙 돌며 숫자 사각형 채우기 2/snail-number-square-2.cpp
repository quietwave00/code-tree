#include <iostream>

using namespace std;

// 남동북서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m;
int arr[100][100];

bool inRange(int a, int b) {
    return a >= 0 && a < n && b >= 0 && b < m;
}

int main() {
    cin >> n >> m;
    arr[0][0] = 1;

    int cx = 0, cy = 0;
    int dir = 0;
    for(int i = 2; i <= n * m; i++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        if(!inRange(nx, ny) || arr[nx][ny] != 0) {
            dir = (dir + 1) % 4;
        }

        cx = cx + dx[dir];
        cy = cy + dy[dir];
        arr[cx][cy] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}