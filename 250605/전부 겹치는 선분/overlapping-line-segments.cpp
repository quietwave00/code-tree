#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
pair<int, int> arr[100];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        arr[i] = make_pair(num1, num2);
    }

    bool overlap = false;
    // 제거 선택
    for(int i = 0; i < N; i++) {
        int max_x1 = 0;
        int min_x2 = INT_MAX;
        for(int j = 0; j < N; j++) {
            if(j == i) continue;

            max_x1 = max(arr[j].first, max_x1);
            min_x2 = min(arr[j].second, min_x2);
        }
        // printf(">>>> min_start: %d, max_end: %d\n", min_start, max_end);
        // cout << "=========" << endl;
        if(min_x2 < max_x1) overlap = false;
        else overlap = true;
    }

    if(overlap) cout << "Yes";
    else cout << "No";
    
    return 0;
}


// 겹치게 만들기
// min_start > max_end