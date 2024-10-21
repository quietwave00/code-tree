#include <iostream>

using namespace std;

#define MAX_K 301

// white = 1;
// black = 2;
// gray = 3;

int arr[MAX_K];
int cnt_b[MAX_K];
int cnt_w[MAX_K];
int b, w, g;

int main() {
    int n;
    cin >> n;

    int cur = MAX_K / 2;
    for(int i = 0; i < n; i++) {
        int x;
        char c;
        cin >> x >> c;
        if(c == 'L') {
            while(x--) {
                arr[cur] = 1;
                cnt_w[cur]++;
                if(x) cur--;
            }
        }
        else {
            while(x--) {
                arr[cur] = 2;
                cnt_b[cur]++;
                if(x) cur++;
            }
        }
    }

    for(int i = 0; i <= MAX_K; i++) {
        if(cnt_b[i] >= 2 && cnt_w[i] >= 2) g++;
        else if(arr[i] == 1) w++;
        else if(arr[i] == 2) b++;
    }
    
    printf("%d %d %d", w, b, g);

    return 0;
}