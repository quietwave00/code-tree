#include <iostream>
using namespace std;

#define MAX 2000
#define OFFSET 1000

int main() {
    int n, m;
    cin >> n >> m;

    int time_a[MAX] = { 0 };
    int time_b[MAX] = { 0 };
    int cur_a = OFFSET, cur_b = OFFSET;
    int current_time = 1; 

    // A
    for (int i = 0; i < n; i++) {
        char cmd;
        int t;
        cin >> cmd >> t;

        for (int j = 0; j < t; j++) {
            if (cmd == 'R') {
                cur_a += 1;
            } else {
                cur_a -= 1;
            }
            time_a[cur_a] = current_time++;
        }
    }

    current_time = 1;

    // B
    for (int i = 0; i < m; i++) {
        char cmd;
        int t;
        cin >> cmd >> t;

        for (int j = 0; j < t; j++) {
            if (cmd == 'R') {
                cur_b += 1;
            } else {
                cur_b -= 1;
            }
            time_b[cur_b] = current_time++; 
        }
    }

    bool flag = false;
    for (int i = 0; i < MAX; i++) {
        if (time_a[i] != 0 && time_b[i] != 0 && time_a[i] == time_b[i]) {
            cout << time_a[i];
            flag = true; 
            break;
        }
    }

    if(!flag) {
        cout << -1;
    }

    return 0;
}