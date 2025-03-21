#include <iostream>

using namespace std;

int X, Y;

int Sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    cin >> X >> Y;
    
    int max_sum = 0;
    for (int num = X; num <= Y; num++) {
        int sum = Sum(num);
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    
    cout << max_sum << endl;
    
    return 0;
}