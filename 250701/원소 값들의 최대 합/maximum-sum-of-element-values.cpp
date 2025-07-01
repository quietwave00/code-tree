#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];
int N, M;

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int max_sum = 0;
    // 시작 위치별
    for(int pos = 1; pos <= N; pos++) {
        // M번 반복
        int sum = 0;
        int cur = pos;
        int cnt = M;
        while(cnt--) {
            sum += arr[cur];
            cur = arr[cur];
        }
        max_sum = max(sum, max_sum);
    }

    cout << max_sum << endl;

    return 0;
}

// N
// 시작위치별