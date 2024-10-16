#include <iostream>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    int digits[32];
    int idx = 0;
    while (n > 0) {
        digits[idx++] = n % b;
        n /= b;
    }

    for(int i = idx - 1; i >= 0; i--) {
        cout << digits[i];
    }
    
    return 0;
}