#include <iostream>
using namespace std;

int N, r, c, max_cnt;
int arr[4 + 1][4 + 1];
int dir_arr[4 + 1][4 + 1];
int dir_def[8][2] = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
    {1, 0}, {1, -1}, {0, -1}, {-1, -1}
};

// 1 based!!
bool InRange(int row, int col) {
    return row >= 1 && row <= N && col >= 1 && col <= N;
}

void Choose(int row, int col, int cnt) {
    max_cnt = max(max_cnt, cnt);
    
    int dir = dir_arr[row][col];
    
    int jump = 1;
    while(true) {
        int nr = row + dir_def[dir][0] * jump;
        int nc = col + dir_def[dir][1] * jump;
        
        if(!InRange(nr, nc)) break;
        
        if(arr[nr][nc] > arr[row][col]) {
            Choose(nr, nc, cnt + 1);
        }
        jump++;
    }
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int num;
            cin >> num;
            dir_arr[i][j] = num - 1;
        }
    }
    cin >> r >> c;

    Choose(r, c, 0);

    cout << max_cnt << endl;

    return 0;
}
/*
칸: 정수(<= N * N, 중복x), 8방향
이동 방향 최댓값

경로가 조합의 대상...중복 선택 X
시작 위치의 라인에 있는 숫자를 대상으로 모든 경로 조합 만들어보기?
재귀호출마다 cnt++;
*/