#include <iostream>
using namespace std;

char arr[100][100];

// 동남서북
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0}; 

int n, m;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    cin >> n >> m;

    int cx = 0, cy = 0;
    char ch = 'A';
    arr[cx][cy] = ch;

    int dir = 0;
    for(int i = 1; i < n * m; i++) {
        while(true) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            // cout << "nx: " << nx << " ny: " << ny << " InRange: " << InRange(nx, ny) << endl;
            if(InRange(nx, ny) && arr[nx][ny] == '\0') {
                cx = nx;
                cy = ny;
                ch++;
                arr[cx][cy] = ch;
                break;
            } else {
                dir = (dir + 3) % 4;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}