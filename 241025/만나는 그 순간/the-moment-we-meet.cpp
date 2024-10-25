#include <iostream>
using namespace std;

#define MAX 2000
#define OFFSET 1000

int main() {
    int n, m; // A, B
    cin >> n >> m;

    int time_a[MAX] = { 0 };
    int time_b[MAX] = { 0 };
    int cur_a = OFFSET, cur_b = OFFSET;
    // A
    for(int i = 0; i < n; i++) {
        char cmd; int t;
        cin >> cmd >> t;

        if(cmd == 'R') {
            cur_a += t;
        }
        else {
            cur_a -= t;
        }
        time_a[cur_a] = cur_a;
    }

    // B
    for(int i = 0; i < m; i++) {
        char cmd; int t;
        cin >> cmd >> t;

        if(cmd == 'R') {
            cur_b += t;
        }

        else {
            cur_b -= t;
        }
        time_b[cur_b] = cur_b;
    }

    // for(int i = 0; i < MAX; i++) {
    //     if(time_a[i] != 0) {
    //         cout << "a- " << i << ": " << time_a[i] << endl;
    //     }
    // }

    // for(int i = 0; i < MAX; i++) {
    //     if(time_b[i] != 0) {
    //         cout << "b- " << i << ": " << time_b[i] << endl;
    //     }   
    // }

    for(int i = 0; i < MAX; i++) {
        if(time_a[i] != 0 && time_b[i] != 0 && time_a[i] == time_b[i]) {
            cout << i - OFFSET + 1;
            break;
        }
    }

    return 0;
}