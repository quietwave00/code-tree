#include <iostream>
using namespace std;

// 북 동 남 서
// dir_num = (dir_num + 1) % 4;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[100][100];
int n, m;

bool InRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main() {
    cin >> n >> m;

    arr[0][0] = 1;
    int cur_x = 0, cur_y = 0;
    int dir = 0;
    for(int i = 2; i <= n * m; i++) {
        // cout << "i: " << i << endl;
        int nx = cur_x + dx[dir];
        int ny = cur_y + dy[dir];

        if(!InRange(nx, ny) || arr[nx][ny] != 0) {
            dir = (dir + 1) % 4;
        }
        cur_x = cur_x + dx[dir];
        cur_y = cur_y + dy[dir];

        // cout << "cur_x: " << cur_x << endl;
        // cout << "cur_y: " << cur_y << endl;
        
        arr[cur_x][cur_y] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




