#include <iostream>
using namespace std;

// 동남서북
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n][n] = { 0 };
    for(int i = 0; i < m; i++) {
        int num1, num2;
        cin >> num1 >> num2;

        arr[num1 - 1][num2 - 1] = 1;
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            int nx = num1 - 1 + dx[j];
            int ny = num2 - 1 + dy[j];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // cout << "nx: " << nx << ", ny: " << ny << endl;
                if(arr[nx][ny] == 1) cnt++;
            }
        }

        if(cnt == 3) cout << 1 << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}