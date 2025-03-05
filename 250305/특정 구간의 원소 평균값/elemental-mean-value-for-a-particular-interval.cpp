#include <iostream>
using namespace std;

int N;
int arr[101];

bool Includes(int num) {
    // cout << "num: " << num << endl;
    for(int i = 1; i <= N; i++) {
        if(arr[i] == num) return true;
    }
    return false;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    for(int size = 1; size <= N; size++) {
        for(int i = 1; i <= N - size + 1; i++) {
            int sum = 0;
            for(int j = 0; j < size; j++) {
                sum += arr[i + j];
            }
            if(sum % size == 0) { 
                int avg = sum / size;
                if(Includes(avg)) cnt++;
            }
        }
        // cout << "=======" << endl;
    }

    cout << cnt << endl;

    return 0;
}

// 구간 size: 1~N
// 시작 int i = 0, 끝 i < N