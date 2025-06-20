#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int X;
    cin >> X;
    
    int k = ceil(sqrt(X));
    
    if (k * k - k < X) {
        cout << 2 * k - 1 << endl;
    } else {
        cout << 2 * k - 2 << endl;
    }
    
    return 0;
}




// 시작 1m/s, 도착지에선 속력 1m/s

// 10
// 1 2 3 4 5 6 7 8 9 10
// 1 2 2 3 3 3 2 2 1 1