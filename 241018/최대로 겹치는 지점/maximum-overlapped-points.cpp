#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100 + 1] = { 0 };
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for(int j = a; j <= b; j++) {
            arr[j]++;
        }
    }    

    int max = 0;
    for(int i = 1; i <= 100; i++) {
        if(arr[i] > max) max = arr[i];
    }

    cout << max << '\n';

    return 0;
}