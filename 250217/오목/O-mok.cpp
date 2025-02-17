#include <iostream>

using namespace std;

int board[19][19];

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];

    for(int i = 0; i < 19; i++) {    
        for(int j = 0; j < 19; j++) {
            int cur = board[i][j];

            if (cur == 0) continue;

            // 가로
            if (j + 4 < 19) {
                if (cur == board[i][j + 1] && cur == board[i][j + 2] &&
                    cur == board[i][j + 3] && cur == board[i][j + 4]) {
                    cout << cur << endl;
                    cout << i + 1 << " " << j + 3 << endl;
                    return 0;
                }
            }

            // 세로
            if (i + 4 < 19) {
                if (cur == board[i + 1][j] && cur == board[i + 2][j] &&
                    cur == board[i + 3][j] && cur == board[i + 4][j]) {
                    cout << cur << endl;
                    cout << i + 3 << " " << j + 1 << endl;
                    return 0;
                }
            }

            // 대각선 
            if (i + 4 < 19 && j + 4 < 19) {
                if (cur == board[i + 1][j + 1] && cur == board[i + 2][j + 2] &&
                    cur == board[i + 3][j + 3] && cur == board[i + 4][j + 4]) {
                    cout << cur << endl;
                    cout << i + 3 << " " << j + 3 << endl;
                    return 0;
                }
            }

            // 대각선 /
            if (i - 4 >= 0 && j + 4 < 19) {
                if (cur == board[i - 1][j + 1] && cur == board[i - 2][j + 2] &&
                    cur == board[i - 3][j + 3] && cur == board[i - 4][j + 4]) {\
                    cout << cur << endl;
                    cout << i - 1 << " " << j + 3 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "0" << endl;
    return 0;
}
