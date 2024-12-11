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

    int max_count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 2; j++) {
            int count = 0;
            for(int k = j; k < j + 3; k++) {
                // printf("arr[%d][%d]: %d\n", i, k, arr[i][k]);
                if(arr[i][k] == 1) count++;
            }
            max_count = max(max_count, count);
        }
    }

    cout << max_count;

    return 0;
}



