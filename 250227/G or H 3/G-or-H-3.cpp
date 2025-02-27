#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
pair<bool, int> arr[10000 + 1];


int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int idx;
        char ch; 
        cin >> idx >> ch;

        arr[idx].first = true;
        arr[idx].second = (ch == 'G') ? 1 : 2;
    }

    int max_num = 0;
    for(int i = 1; i <= 10000; i++) {
        int sum = 0;
        for(int j = i; j <= i + K; j++) {
            if(j >= 10000) continue;
            if(arr[j].first == true) {
                sum += arr[j].second;
                // cout << "arr[j].second: " << arr[j].second << endl;
            } 
        }
        // cout << "sum: " << sum << endl;
        max_num = max(sum, max_num);
    }

    cout << max_num << endl;

    return 0;
}

// 1 ~ N
// G -> +1, H -> +2
// size = K + 1
