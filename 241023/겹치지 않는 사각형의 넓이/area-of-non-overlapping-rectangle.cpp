#include <iostream>
using namespace std;

#define MAX 2000
#define OFFSET 1000

int main() {
    
    int arr[MAX][MAX] = { 0 };
    for(int i = 0; i < 3; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += OFFSET; y1 += OFFSET; x2 += OFFSET; y2 += OFFSET;

        for(int j = x1; j <= x2 - 1; j++) {
            for(int k = y1; k <= y2 - 1; k++) {
                arr[j][k]++;
            }
        }

        // 직사각형 M 연산
        if(i == 2) { 
            for(int j = x1; j <= x2 - 1; j++) {
                for(int k = y1; k <= y2 - 1; k++) {
                    arr[j][k] = 0;
                }
            }   
        }
    }

    // 카운팅
    int cnt = 0;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(arr[i][j] > 0) cnt++;
        }
    }

    cout << cnt;

    return 0;
}