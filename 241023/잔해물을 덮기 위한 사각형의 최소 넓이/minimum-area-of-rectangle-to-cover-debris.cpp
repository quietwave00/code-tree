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

    // 잔해물 좌표
    vector<pair<int, int>> vec; 
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(arr[i][j] > 0) {
                vec.push_back(make_pair(i, j));
            }
        }
    }

    sort(vec.begin(), vec.end());

    int x1 = vec.front().first;
    int y1 = vec.front().second;
    int x2 = vec.back().first + 1;
    int y2 = vec.back().second + 1;

    cout << (x2 - x1) * (y2 - y1);

    return 0;
}