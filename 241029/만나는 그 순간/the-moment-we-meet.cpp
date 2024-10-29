#include <iostream>

#define MAX 1000000

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    int pos_a[MAX + 1] = { 0 };
    int pos_b[MAX + 1] = { 0 };

    // A
    int cur_a = 1;
    for(int i = 0; i < n; i++) {
        char d; int t;
        cin >> d >> t;

        while(t--) {
            if(d == 'R') pos_a[cur_a] = pos_a[cur_a - 1] + 1;
            else pos_a[cur_a] = pos_a[cur_a - 1] - 1;
            cur_a++;
        }
        
    }

    // B
    int cur_b = 1;
    for(int i = 0; i < m; i++) {
        char d; int t;
        cin >> d >> t;

        while(t--) {
            if(d == 'R') pos_b[cur_b] = pos_b[cur_b - 1] + 1;
            else pos_b[cur_b] = pos_b[cur_b - 1] - 1;
            cur_b++;
        }
    }

    // 같은 위치
    int answer = -1;
    for(int i = 1; i < cur_a; i++) {
        if(pos_a[i] == pos_b[i]) {
            answer = i;
            break;
        }
    }

    cout << answer;

    return 0;
}