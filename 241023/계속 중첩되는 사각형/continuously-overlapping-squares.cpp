#include <iostream>
using namespace std;

#define MAX 200
#define OFFSET 100

int main() {
    int n;
    cin >> n;

    int arr[MAX][MAX] = { 0 };
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += OFFSET;
        y1 += OFFSET;
        x2 += OFFSET;
        y2 += OFFSET; 

        // 빨강== 1
        if(i % 2 == 0) {
            for(int j = x1; j < x2; j++) {
                for(int k = y1; k < y2; k++) {
                    arr[j][k] = 1;
                }
            }
        }

        // 파랑 == 2
        else {
            for(int j = x1; j < x2; j++) {
                for(int k = y1; k < y2; k++) {
                    arr[j][k] = 2;
                }
            }
        }
    }

    int area = 0;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(arr[i][j] == 2) area++;
        }
    }

    cout << area;

    return 0;
}