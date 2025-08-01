#include <iostream>
using namespace std;

int N, M;
int arr[100][100];

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    // 행 체크
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int cnt = 1;
            int target = arr[i][j];
            for(int k = 1; k < M; k++) {
                if(j + k >= N) continue;
                if(target != arr[i][j + k]) break;
                cnt++;
            }
            if(cnt >= M) {
                answer++;
                break;
            }
        }
    }

    // 열 체크
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int cnt = 1;
            int target = arr[j][i];
            for(int k = 1; k < M; k++) {
                if(j + k >= N) continue;
                if(target != arr[j + k][i]) break;
                cnt++;
            }
            if(cnt >= M) {
                answer++;
                break;
            }
        }
        
    }

    cout << answer << endl;

    return 0;
}