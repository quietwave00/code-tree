#include <iostream>
using namespace std;

int main() {
    int arr[101] = { 0 };
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        for(int i = a; i <= b; i++) {
            arr[i] += 1;
        }
    }

    int max = 0;
    for(int i = 1; i <= 7; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    cout << max << '\n';

    return 0;
}