#include <iostream>
#include <algorithm>

#define MAX_N 20

int N;
int arr[MAX_N][MAX_N];

using namespace std;

bool InRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int max_cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int cnt = 0;
            for(int tx = 0; tx < 3; tx++) {
                for(int ty = 0; ty < 3; ty++) {
                    if(InRange(i + tx, j + ty) && arr[i + tx][j + ty]) cnt++;
                }
            }
            max_cnt = max(cnt, max_cnt);
        }
    }

    cout << max_cnt << endl;
    
    return 0;
}

// N * N -> 3 * 3