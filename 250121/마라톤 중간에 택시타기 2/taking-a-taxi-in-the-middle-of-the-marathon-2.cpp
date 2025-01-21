#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int n;
int x[100];
int y[100];

int cal_distance(int skip) {
    int totalDistance = 0;
    int prevIndex = -1;

    for (int i = 0; i < n; i++) {
        if (i == skip) continue; // skip 좌표 건너뛰기
        if (prevIndex != -1) {
            totalDistance += abs(x[i] - x[prevIndex]) + abs(y[i] - y[prevIndex]);
        }
        prevIndex = i; // 현재 좌표를 이전 좌표로 업데이트
    }

    return totalDistance;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // 하나씩 다 건너띄워 보기
    int minD = INT_MAX;
    for(int skip = 1; skip < n - 1; skip++) {
        for(int j = 0; j < n; j++) {
            int d = cal_distance(skip);
            minD = min(minD, d);
        }
    }

    cout << minD << endl;

    return 0;
}