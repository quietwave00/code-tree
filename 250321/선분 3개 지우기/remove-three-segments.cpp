#include <iostream>

using namespace std;

int N;
int s[10];
int e[10];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s[i] >> e[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                bool flag = false;
                int arr[101] = { 0 };
                for(int a = 0; a < N; a++) {
                    if(a == i || a == j || a == k) continue;

                    for(int idx = s[a]; idx <= e[a]; idx++) arr[idx]++;
                }

                for(int a = 0; a <= 100; a++) {
                    if(arr[a] > 1) flag = true;
                }

                if(!flag) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

// 3개 다 골라보기
