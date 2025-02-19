#include <iostream>

#define DIR_NUM 8

using namespace std;

// row col
int board[19][19];


int dx[DIR_NUM] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[DIR_NUM] = {-1, 0, 1, -1, 0, 1, -1, 1};

int InRange(int row, int col) {
    return 0 <= row && row < 19 && 0 <= col && col < 19;
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];

    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {

            if(board[i][j] == 0) continue;

            for(int dir = 0; dir < DIR_NUM; dir++) {
                int cnt = 1;
                int curx = i;
                int cury = j;
                while(true) {
                    int nx = curx + dx[dir];
                    int ny = cury + dy[dir];
                    if(!InRange(nx, ny)) break;
                    if(board[nx][ny] != board[i][j]) break;
                    cnt++;
                    curx = nx;
                    cury = ny;
                }

                if(cnt == 5) {
                    cout << board[i][j] << endl;
                    printf("%d %d", i + 2 * dx[dir] + 1, j + 2 * dy[dir] + 1);
                    return 0;
                }
            }
        }
    }

    cout << 0 << endl;
    

    return 0;
}



// int main() {
//     for (int i = 0; i < 19; i++)
//         for (int j = 0; j < 19; j++) cin >> board[i][j];

//     for(int i = 0; i < 19; i++) {    
//         for(int j = 0; j < 19; j++) {
//             int cur = board[i][j];

//             if (cur == 0) continue;

//             // 가로
//             if (j + 4 < 19) {
//                 if (cur == board[i][j + 1] && cur == board[i][j + 2] &&
//                     cur == board[i][j + 3] && cur == board[i][j + 4]) {
//                     cout << cur << endl;
//                     cout << i + 1 << " " << j + 3 << endl;
//                     return 0;
//                 }
//             }

//             // 세로
//             if (i + 4 < 19) {
//                 if (cur == board[i + 1][j] && cur == board[i + 2][j] &&
//                     cur == board[i + 3][j] && cur == board[i + 4][j]) {
//                     cout << cur << endl;
//                     cout << i + 3 << " " << j + 1 << endl;
//                     return 0;
//                 }
//             }

//             // 대각선 
//             if (i + 4 < 19 && j + 4 < 19) {
//                 if (cur == board[i + 1][j + 1] && cur == board[i + 2][j + 2] &&
//                     cur == board[i + 3][j + 3] && cur == board[i + 4][j + 4]) {
//                     cout << cur << endl;
//                     cout << i + 3 << " " << j + 3 << endl;
//                     return 0;
//                 }
//             }

//             // 대각선 /
//             if (i - 4 >= 0 && j + 4 < 19) {
//                 if (cur == board[i - 1][j + 1] && cur == board[i - 2][j + 2] &&
//                     cur == board[i - 3][j + 3] && cur == board[i - 4][j + 4]) {\
//                     cout << cur << endl;
//                     cout << i - 1 << " " << j + 3 << endl;
//                     return 0;
//                 }
//             }
//         }
//     }
//     cout << "0" << endl;
//     return 0;
// }
