#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define MAX INT_MAX

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min_d = MAX;
    for(int i = 0; i < n; i++) { // arr[i] 기준
        int d = 0;
        for(int j = 0; j < n; j++) {
            if(j != i) { // 같은 위치 아니면
                // cout << "abs(j - i): " << abs(j - i) << ", arr[j]: " << arr[j] << endl;
                d += abs(j - i) * arr[j];
            }
        }
        min_d = min(d, min_d);
    }

    cout << min_d << endl;

    return 0;
}

// 1, 2, 3, ... , n
// A1, A2, A3, ... , An
