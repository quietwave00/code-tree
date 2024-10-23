#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2000
#define OFFSET 1000

int main() {
    int arr[MAX][MAX] = { 0 };
    for(int i = 0; i < 2; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += OFFSET;
        y1 += OFFSET;
        x2 += OFFSET;
        y2 += OFFSET;

        for(int j = x1; j < x2; j++) { // 첫 번째 놓음
            for(int k = y1; k < y2; k++) {
                arr[j][k]++;
            }
        }

        if(i == 1) { // 두 번째로 덮음
            for(int j = x1; j < x2; j++) {
                for(int k = y1; k < y2; k++) {
                    arr[j][k] = 0;
                }
            }
        }
    }

    bool flag = false;
    int max_x = 0, max_y = 0, min_x = MAX, min_y = MAX;
    for(int x = 0; x < MAX; x++) {
        for(int y = 0; y < MAX; y++) {
            if(arr[x][y]) {
                flag = true;
                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
        }
    }

    int area = 0;
    if(!flag) area = 0;
    else area = (max_x - min_x + 1) * (max_y - min_y + 1);

    cout << area;

    return 0;
}