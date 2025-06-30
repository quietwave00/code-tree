#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int arr[100][100]; // (x, y)

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    int M = INT_MAX;
    for(int x = 0; x <= 100; x += 2) {
        for(int y = 0; y <= 100; y += 2) {
            int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0, cnt_4 = 0;
            int max_cnt = 0;
            for(int n = 0; n < N; n++) {
                if(arr[n][0] < x && arr[n][1] > y) {
                    cnt_1++;
                    max_cnt = max(cnt_1, max_cnt);
                }
                else if(arr[n][0] > x && arr[n][1] > y) {
                    cnt_2++;
                    max_cnt = max(cnt_2, max_cnt);
                }
                else if(arr[n][0] < x && arr[n][1] < y) {
                    cnt_3++;
                    max_cnt = max(cnt_3, max_cnt);
                }
                else if(arr[n][0] > x && arr[n][1] < y) {
                    cnt_4++;
                    max_cnt = max(cnt_4, max_cnt);
                }
            }
            // printf("x: %d, y: %d, cnt_1: %d, cnt_2: %d, cnt_3: %d, cnt_4: %d\n", x, y, cnt_1, cnt_2, cnt_3, cnt_4);
            M = min(M, max_cnt);
        }
        
    }

    cout << M;

    return 0;
}

// N개의 점
// 가장 많은 점(M개)의 수 최소값?

// x, y(짝수값)을 모두 가정해보기
// 1사분면
// arr[n][0] < x
// arr[n][1] > y

// 2사분면
// arr[n][0] > x
// arr[n][1] > y

// 3사분면
// arr[n][0] < x
// arr[n][1] < y

// 4사분면
// arr[n][0] > x
// arr[n][1] < y