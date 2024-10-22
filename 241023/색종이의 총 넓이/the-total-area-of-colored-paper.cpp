#include <iostream>
using namespace std;

#define MAX 200
#define OFFSET 100
#define LENGTH 8

int main() {
    int n;
    cin >> n;

    int arr[MAX][MAX] = { 0 };
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x += OFFSET; y += OFFSET;

        for(int j = x; j <= x + LENGTH - 1; j++) {
            for(int k = y; k <= y + LENGTH - 1; k++) {
                arr[j][k]++;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(arr[i][j] > 0) cnt++;
        }
    }

    cout << cnt;


    return 0;
}