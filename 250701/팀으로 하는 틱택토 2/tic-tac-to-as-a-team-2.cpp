#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstring>
using namespace std;
int arr[3][3];
int cnt = 0;
bool isBingo(int board[3][3]) {
    // 가로, 세로
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0) return true;
        if(board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0) return true;
    }
    // 대각선
    if(board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0) return true; 
    if(board[0][2] == 0 && board[1][1] == 0 && board[2][0] == 0) return true;
    
    return false;
}
void Check(int a, int b) {
    int board_ab[3][3];
    int board_a[3][3];
    int board_b[3][3];

    memcpy(board_ab, arr, sizeof(arr));
    memcpy(board_a, arr, sizeof(arr));
    memcpy(board_b, arr, sizeof(arr));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board_ab[i][j] == a || board_ab[i][j] == b) { 
                board_ab[i][j] = 0;
            }
            if(board_a[i][j] == a) {
                board_a[i][j] = 0;
            }
            if(board_b[i][j] == b) {
                board_b[i][j] = 0;
            }
        }
    }

    bool bingo_ab = isBingo(board_ab);
    bool bingo_a = isBingo(board_a);
    bool bingo_b = isBingo(board_b);
    
    if (bingo_ab && !(bingo_a && !bingo_b) && !(bingo_b && !bingo_a)) {
        cnt++;
    }
}

int main() {
    for(int i = 0; i < 3; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < 3; j++) {
            arr[i][j] = line[j] - '0';
        }
    }

    // 중복 제거
    set<int> s;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            s.insert(arr[i][j]);
        }
    }

    vector<int> vec(s.begin(), s.end());
    for(int i = 0; i < vec.size(); i++) {
        for(int j = i + 1; j < vec.size(); j++) {
            Check(vec[i], vec[j]);
        }
    }

    cout << cnt << endl;

    return 0;
}