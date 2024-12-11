#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n][n] = { 0 };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    int max_count = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i; j < i + 3; j++) {
            if(arr[i][j] == 1) count++;
        }
        max_count = (max_count, count);
    }

    cout << max_count;

    return 0;
}