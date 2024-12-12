#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    bool arr[r][c];
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            char ch;
            cin >> ch;
            if(ch == 'W') arr[i][j] = false;
            else arr[i][j] = true;
        }
    }

    bool cur = arr[0][0];
    int cnt = 0;
    for(int i = 1; i < c; i++) {
        for(int j = 1; j < r; j++) { // 첫 번째 점프
            // printf("arr[%d][%d]: %d\n", i + 1, j + 1, arr[i][j]);
            if(arr[i][j] != cur) { // 다른 값 만나면 두 번째 점프
                cur = arr[i][j];
                // cout << "====== second start ======" << endl;
                for(int k = i + 1; k < c - 1; k++) {
                    for(int l = j + 1; l < r - 1; l++) {
                        // printf("arr[%d][%d]: %d\n", k + 1, l + 1, arr[k][l]);
                        if(arr[k][l] != cur) {
                            if(arr[c][r] != cur) {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << cnt;

    return 0;
}