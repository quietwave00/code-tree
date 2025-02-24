#include <iostream>
#include <algorithm>

using namespace std;

int arr[20][20];
int N;

bool InRange(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

int Count(int x1, int y1, int x2, int y2) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (InRange(x1, y1 + i) && arr[x1][y1 + i]) count++;
        if (InRange(x2, y2 + i) && arr[x2][y2 + i]) count++;
    }
    return count;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int maxCount = 0;
    for (int i1 = 0; i1 < N; i1++) {
        for (int j1 = 0; j1 < N; j1++) {
            for (int i2 = 0; i2 < N; i2++) {
                for (int j2 = 0; j2 < N; j2++) {
                    // 겹치지 않을 때만...
                    if (j1 + 2 < j2 || j2 + 2 < j1 || i1 != i2) {
                        int count = Count(i1, j1, i2, j2);
                        maxCount = max(maxCount, count);
                    }
                }
            }
        }
    }

    cout << maxCount << endl;

    return 0;
}
