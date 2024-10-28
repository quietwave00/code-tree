#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int arr[n + 1] = { 0 };
    int answer = -1;
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        arr[num]++;

        if(arr[num] == k) {
            answer = num;
            break;
        }
    }

    cout << answer;

    return 0;
}