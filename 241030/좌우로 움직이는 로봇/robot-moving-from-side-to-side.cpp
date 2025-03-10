#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000

int main() {
    int n, m;
    cin >> n >> m;

    int pos_a[MAX + 1] = { 0 };
    int pos_b[MAX + 1] = { 0 };

    // A의 이동 정보를 기록
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

    // B의 이동 정보를 기록
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

    // 위치 보정
	if(time_a < time_b) {
		for(int i = time_a; i < time_b; i++) {
			pos_a[i] = pos_a[i - 1];
		}
	}
	else if(time_a > time_b) {
		for(int i = time_b; i < time_a; i++) {
			pos_b[i] = pos_b[i - 1];
		}
	}

    // 일치하는 횟수
    int cnt = 0;
	int size = max(time_a, time_b);
    for(int i = 1; i < size; i++) {
        if(pos_a[i] == pos_b[i] && pos_a[i - 1] != pos_b[i - 1])
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}