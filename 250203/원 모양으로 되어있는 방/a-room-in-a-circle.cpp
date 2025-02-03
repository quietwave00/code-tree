#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int a[1003];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int minD = INT_MAX;
    for(int i = 0; i < n; i++) { // 이동거리 변경
        int num = 0;
        for (int j = 0; j < n; j++) {
            int idx = (n - (n - i) + j) % n; // 순회
            num += j * a[idx];
            // cout << "i: " << i << ", idx: " << idx << ", num: " << num << endl;
        }
        minD = min(minD, num);
    }

    cout << minD << endl;

    return 0;
}