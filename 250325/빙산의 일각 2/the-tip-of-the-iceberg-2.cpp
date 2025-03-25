#include <iostream>
#include <algorithm>

using namespace std;

int N;
int H[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int max_cnt = 0;

    for (int h = 1; h <= 1000; h++) { // h 기준
        int check[100] = { 0 };
        for (int i = 0; i < N; i++) {
            if (H[i] > h) check[i] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (check[i] == 1 && (i == 0 || check[i - 1] == 0)) {
                cnt++;
            }
        }
        max_cnt = max(cnt, max_cnt);
    }

    cout << max_cnt << endl;

    return 0;
}
