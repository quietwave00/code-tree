#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int arr[100];

int Check(int K) {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int diff = abs(K - arr[i]);
            int diff2 = abs(K - arr[j]);
            if(diff == diff2) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i ++) { 
        cin >> arr[i];
    }

    int max_cnt = 0;
    for(int K = 1; K <= 100; K++) { // K 기준
        int cnt = 0;
        cnt += Check(K);
        max_cnt = max(cnt, max_cnt);
    }

    cout << max_cnt << endl;
    
    return 0;
}

// N개의 수, K 
// j - K, K - a
// 수를 각 인덱스에 넣어보고 등차수열 체크