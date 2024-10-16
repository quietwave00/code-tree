#include <iostream>
#include <string>

using namespace std;

int main() {
    string n; // 이진수
    cin >> n;

    // 십진수로 변환
    int digits[n.length()];
    for(int i = 0; i < n.length(); i++) {
        digits[i] = n[i] - '0';
    }

    int num = 0;
    for(int i = 0; i < n.length(); i++) {
        num = num * 2 + digits[i];
    }

    num *= 17;

    // 이진수로 변환
    int binary[20];
    int idx = 0;
    while(num > 0) {
        binary[idx++] = num % 2;
        num /= 2;
    }

    for(int i = idx - 1; i >= 0; i--) {
        cout << binary[i];
    }

    return 0;
}