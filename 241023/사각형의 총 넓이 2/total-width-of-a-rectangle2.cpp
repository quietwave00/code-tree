#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[200][200] = { 0 };
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += 100;
        y1 += 100;
        x2 += 100;
        y2 += 100;
        
        // arr[x1][y1] ~ arr[x2][y2]
        for(int j = x1; j <= x2 - 1; j++) {
            for(int k = y1; k <= y2 - 1; k++) {
                arr[j][k]++;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            if(arr[i][j] > 0) cnt++;
        }
    }

    cout << cnt;

    return 0;
}