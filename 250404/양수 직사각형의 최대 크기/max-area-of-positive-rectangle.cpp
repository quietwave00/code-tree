#include <iostream>

using namespace std;

int N, M;
int arr[20][20];

int GetSize(int r1, int c1, int r2, int c2) {
    int cnt = 0;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if(arr[i][j] <= 0) return 0;
            cnt++;
        }
    }
    return cnt;
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int max_size = 0;
    for (int r1a = 0; r1a < N; r1a++) {
        for (int c1a = 0; c1a < M; c1a++) {
            for (int r2a = r1a; r2a < N; r2a++) {
                for (int c2a = c1a; c2a < M; c2a++) {
                    int size = GetSize(r1a, c1a, r2a, c2a);
                    max_size = max(size, max_size);
                }
            }
        }
    }

    max_size == 0 ? cout << -1 << endl : cout << max_size << endl;

    return 0;
}

// N * M -> 직사각형 범위 잡기, 음수면 건너띄기