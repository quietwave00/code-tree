#include <iostream>
#include <algorithm>

using namespace std;

int N;
int pos;
char arr[101];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> pos;
        cin >> arr[pos];
    }

    int max_num = 0;
    for(int s = 0; s <= 99; s++) {
        for(int e = s + 1; e <= 100; e++) {
            bool flag = true;
            int G_cnt = 0, H_cnt = 0;
            for(int i = s; i <= e; i++) {
                if(arr[i] == 'G') G_cnt++;
                if(arr[i] == 'H') H_cnt++;

                if(G_cnt == H_cnt) {
                    cout << "i: " << i << endl;
                    max_num = max(e - i, max_num);
                }
                if(G_cnt == 0 || H_cnt == 0) {
                    max_num = max(e - i, max_num);
                }
            }
        }
    }

    cout << max_num << endl;

    return 0;
}

// 0~1, 0~2, 0~3, ... 0~100
// 1~2, 1~3, 1~4, ... 1~100
// 2~3, 2~4, 2~5, ... 2~100
// 99~100