#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[20][2];

bool Check(int idx1, int idx2, int idx3) {
    for(int i = 0; i < N; i++) {
        bool x = (arr[i][1] == idx1 || arr[i][1] == idx2 || arr[i][1] == idx3);
        bool y = (arr[i][0] == idx1 || arr[i][0] == idx2 || arr[i][0] == idx3);

        if (!x && !y) return false;
    }
    return true;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i <= 10; i++) {
        for(int j = i + 1; j <= 10; j++) {
            for(int k = j + 1; k <= 10; k++) {
                if(Check(i, j, k)) result = 1;
            }
        }
    }

    cout << result << endl;

    return 0;
}

// N개 점
// 가로 세로 3개 
// x축 평행 (0, 1)(0, 2)...
// y축 평행 (1, 0)(2, 0)...
// 1, 2, 3, 4, 5, ...
// i = 1, j = 2, k = 3
// 