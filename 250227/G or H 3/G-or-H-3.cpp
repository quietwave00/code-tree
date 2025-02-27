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
    for(int i = 1; i <= 10001; i++) {
        int sum = 0;
        for(int j = 1; j <= K + 1; j++) {
            if(arr[j].first == true) {
                sum += arr[j].second;
            } 
        }
        max_num = max(sum, max_num);
    }

    cout << max_num << endl;

    return 0;
}

// 1 ~ N
// G -> +1, H -> +2
// size = K + 1
