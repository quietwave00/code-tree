#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    string n;
    cin >> a >> b >> n;

    // 십진수로 변환
    int digits[n.length()];
    for(int i = 0; i < n.length(); i++) {
        digits[i] = n[i] - '0';
    }

    int num = 0;
    for(int i = 0; i < n.length(); i++) {
        num = num * a + digits[i];
    }

    // b진수 변환
    int arr[20];
    int idx = 0;
    while(num > 0) {
        arr[idx++] = num % b;
        num /= b;
    }

    for(int i = idx - 1; i >= 0; i--) {
        cout << arr[i];
    }


    return 0;
}