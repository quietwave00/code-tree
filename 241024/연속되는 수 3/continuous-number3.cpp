#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n] = { 0 };
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0, answer = 0;
    for(int i = 0; i < n; i++) {
        // 이전 인덱스와 일치하는 경우
        if((arr[i] > 0 && arr[i - 1] > 0) || (arr[i] < 0 && arr[i - 1] < 0)) {
            cnt++;
        }

        // 이전 인덱스와 불일치하는 경우
        if(i == 0 || (arr[i] > 0 && arr[i - 1] < 0) || (arr[i] < 0 && arr[i - 1] > 0)) {
            cnt = 1;
        }

        answer = max(answer, cnt);
    }

    cout << answer;
    
    return 0;
}