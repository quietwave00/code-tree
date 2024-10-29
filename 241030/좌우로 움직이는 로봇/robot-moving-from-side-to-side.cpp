#include <iostream>
using namespace std;

#define MAX 1000000

int main() {
    int n, m;
    cin >> n >> m;

    int pos_a[MAX + 1] = { 0 };
    int pos_b[MAX + 1] = { 0 };

    // A
    int time_a = 1;
    for(int i = 0; i < n; i++) {
        int t; char d;
        cin >> t >> d;

        while(t--) {
            if(d == 'R') pos_a[time_a] = pos_a[time_a - 1] + 1; 
            else pos_a[time_a] = pos_a[time_a - 1] - 1;
            time_a++;
        }
    }

    // B
    int time_b = 1;
    for(int i = 0; i < m; i++) {
        int t; char d;
        cin >> t >> d;

        while(t--) {
            if(d == 'R') pos_b[time_b] = pos_b[time_b - 1] + 1; 
            else pos_b[time_b] = pos_b[time_b - 1] - 1;
            time_b++;
        }
    }

    // for(int i = 1; i <= time_a; i++){
    //     cout << "a: " << pos_a[i] << endl;
    // }

    // for(int i = 1; i <= time_b; i++){
    //     cout << "b: " << pos_b[i] << endl;
    // }

    // 선두 변경 체크
    int answer = 0;
    for(int i = 1; i < time_a; i++) {
        if(pos_a[i] == pos_b[i]) answer++;
    }

    cout << answer - 1;
    
    return 0;
}