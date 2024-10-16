#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    cin >> n;

    int length = n.length();
    int digits[length];

    for (int i = 0; i < length; i++) {
        digits[i] = n[i] - '0';
    }

    // 계산
    int num = 0;
    for(int i = 0; i < length; i++) {
        num = num * 2 + digits[i];
    }

    cout << num;

    return 0;
}