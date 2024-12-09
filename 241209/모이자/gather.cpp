#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX 101

int n;
int arr[MAX];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int m = INT_MAX;
    for(int i = 1; i <= n; i++) { // 기준 집
        int num = 0;
        for(int j = 1; j <= n; j++) { // 사람 수 저장 배열
            num += arr[j] * abs(i - j);
            // cout << arr[j] << " * " << abs(i - j) << endl;
        }
        m = min(m, num);
    }

    cout << m;

    return 0;
}