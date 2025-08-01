#include <iostream>
using namespace std;

int N;
int arr[20][20];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int max_num = 0;
    for(int i = 0; i < N - 2; i++) {
        for(int j = 0; j < N - 2; j++) {
            int sum = 0;
            // 3 * 3 범위 잡기
            for(int k = 0; k < 3; k++) {
                for(int l = 0; l < 3; l++) {
                    sum += arr[i + k][j + l];
                }
            }
            max_num = max(sum, max_num);
        }
    }

    cout << max_num << endl;
    
    return 0;
}

// 3 * 3 범위 잡기
