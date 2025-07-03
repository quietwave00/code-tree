#include <iostream>

using namespace std;

int N, M, Q;
int arr[102][102];
int tempArr[102][102];

void inside(int r1, int c1, int r2, int c2) {
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            // cout << "target: " << arr[i][j] << endl;
            int sum = arr[i][j], cnt = 1;
            // 상
            if (i - 1 >= 1) {
                sum += arr[i - 1][j];
                cnt++;
            }
            // 하
            if (i + 1 <= N) {
                sum += arr[i + 1][j];
                cnt++;
            }
            // 좌
            if (j - 1 >= 1) {
                sum += arr[i][j - 1];
                cnt++;
            }
            // 우
            if (j + 1 <= M) {
                sum += arr[i][j + 1];
                cnt++;
            }
            // cout << "sum: " << sum << ", cnt: " << cnt << endl;
            tempArr[i][j] = sum / cnt;
            // cout << "after: " << tempArr[i][j] << endl;
        }
    }

    // tempArr -> arr
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            arr[i][j] = tempArr[i][j];
        }
    }
}

void doRight(int r1, int c1, int c2) {
    for (int i = c2; i > c1; i--) {
        arr[r1][i] = arr[r1][i - 1];
    }
}

void doDown(int c2, int r1, int r2) {
    for (int i = r2; i > r1; i--) {
        arr[i][c2] = arr[i - 1][c2];
    }
}

void doLeft(int r2, int c2, int c1) {
    for (int i = c1; i < c2; i++) {
        arr[r2][i] = arr[r2][i + 1];
    }
}

void doUp(int c1, int r2, int r1) {
    for (int i = r1; i < r2; i++) {
        arr[i][c1] = arr[i + 1][c1];
    }
}

int main() {
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            tempArr[i][j] = arr[i][j];
        }
    }

    int r1, c1, r2, c2;
    while (Q--) {
        cin >> r1 >> c1 >> r2 >> c2;

        int topRight    = arr[r1][c2];
        int bottomRight = arr[r2][c2];
        int bottomLeft  = arr[r2][c1];
        int topLeft     = arr[r1][c1];

        // 테두리
        doRight(r1, c1, c2);
        doDown(c2, r1, r2);
        doLeft(r2, c2, c1);
        doUp(c1, r2, r1);

        arr[r1 + 1][c2] = topRight;
        arr[r2][c2 - 1] = bottomRight;
        arr[r2 - 1][c1] = bottomLeft;
        arr[r1][c1 + 1] = topLeft;

        // 평균
        inside(r1, c1, r2, c2);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << tempArr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}