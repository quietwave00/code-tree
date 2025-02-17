#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20];

bool isValid(int a, int b) {
    int digit = 1;
    while (digit <= max(a, b)) {
        int digit1 = (a / digit) % 10;
        int digit2 = (b / digit) % 10;

        if (digit1 + digit2 >= 10) return false; // carry 발생
        digit *= 10;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_num = 0;
    bool valid = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!isValid(arr[i], arr[j])) continue; // 두 수의 carry 발생 체크

            for (int k = j + 1; k < n; k++) {
                if (isValid(arr[i] + arr[j], arr[k])) { // 세 번째 숫자까지 carry 체크
                    max_num = max(max_num, arr[i] + arr[j] + arr[k]);
                    valid = true;
                }
            }
        }
    }

    if (!valid) cout << -1 << endl;
    else cout << max_num << endl;

    return 0;
}