#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int MAX = 10 * n + 1;
    int arr[MAX] = { 0 };
    int cur = 10 * n / 2;
    for(int i = 0; i < n; i++) {
        int x;
        char cmd;
        cin >> x >> cmd;
        
        if(cmd == 'R') {
            for(int j = cur; j < cur + x; j++) {
                arr[j]++;
            }
            cur += x;
        }
        else {
            for(int j = cur; j > cur - x; j--) {
                arr[j - 1]++;
            }
            cur -= x;
        }

    }

    int cnt = 0;
    for(int i = 0; i < MAX; i++) {
        if(arr[i] >= 2) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}