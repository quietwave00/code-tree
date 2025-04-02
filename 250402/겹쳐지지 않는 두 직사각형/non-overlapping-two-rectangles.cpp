#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[5][5];

int GetSum(int r1, int c1, int r2, int c2) {
    int sum = 0;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

bool IsOverlap(int r1a, int c1a, int r2a, int c2a, int r1b, int c1b, int r2b, int c2b) {
    return !(r2a < r1b || r2b < r1a || c2a < c1b || c2b < c1a);
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int max_sum = -2000;
    // 첫 번째 직사각형 선택
    for (int r1a = 0; r1a < N; r1a++) {
        for (int c1a = 0; c1a < M; c1a++) {
            for (int r2a = r1a; r2a < N; r2a++) {
                for (int c2a = c1a; c2a < M; c2a++) {
                    int sumA = GetSum(r1a, c1a, r2a, c2a);

                    // 두 번째 직사각형 선택
                    for (int r1b = 0; r1b < N; r1b++) {
                        for (int c1b = 0; c1b < M; c1b++) {
                            for (int r2b = r1b; r2b < N; r2b++) {
                                for (int c2b = c1b; c2b < M; c2b++) {
                                    if (!IsOverlap(r1a, c1a, r2a, c2a, r1b, c1b, r2b, c2b)) {
                                        int sumB = GetSum(r1b, c1b, r2b, c2b);
                                        max_sum = max(sumA + sumB, max_sum);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}

// N * M -> 직사각형 두개잡고 최대합 구하기
// 반복문을?????