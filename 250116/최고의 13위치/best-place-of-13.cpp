#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> grid[i][j];


    int max_cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 2; j++) {
            int cnt = 0;
            for(int k = 0; k < 3; k++) {
                if(grid[i][j + k]) cnt++;
            }
            max_cnt = max(cnt, max_cnt);
        }
    }

    cout << max_cnt << endl;

    return 0;
}


// ㅇㅇㅇㅇㅇ 
// ㅇㅇㅇㅇㅇ
// ㅇㅇㅇㅇㅇ
// ㅇㅇㅇㅇㅇ
// ㅇㅇㅇㅇㅇ

// 0~2
// 1~3
// 2~4

