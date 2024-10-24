#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int arr[n] = { 0 };
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0, answer = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > t) cnt++;
        else cnt = 0;

        answer = max(cnt, answer);
    }

    cout << answer;

    return 0;
}