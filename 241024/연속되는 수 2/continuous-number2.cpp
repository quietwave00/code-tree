#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int cnt_arr[n] = { 0 };
    for(int i = 0; i < n; i++) {
        if(i == 0 || arr[i] != arr[i - 1]) {
            cnt++;
            cnt_arr[i] = cnt;
        }
    }

    sort(cnt_arr, cnt_arr + n);

    cout << cnt_arr[n -1];

    return 0;
}