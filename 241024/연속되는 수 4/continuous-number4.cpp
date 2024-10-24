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
        // 증가하는 경우
        if(i == 0 || arr[i] > arr[i - 1]) {
            cnt++;
        }
        
        // 증가하지 않는 경우
        else {
            cnt = 1;
        }
        answer = max(cnt, answer);
    }

    cout << answer;

    return 0;
}