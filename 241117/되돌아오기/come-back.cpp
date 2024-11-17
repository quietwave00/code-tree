#include <iostream>
using namespace std;

// 동남서북
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int getDir(char ch) {
    int dir;
    switch(ch) {
        case 'E': dir = 0; break; case 'S': dir = 1; break; case 'W': dir = 2; break; case 'N': dir = 3; break;
    }
    return dir;
}

int main() {
    int n;
    cin >> n;

    int dir = 0, cx = 0, cy = 0, cnt = 0, result = 0;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        char dir_ch; int num;
        cin >> dir_ch >> num;

        dir = getDir(dir_ch);
        for(int j = 0; j < num; j++) {
            cx = cx + dx[dir];
            cy = cy + dy[dir];
            cnt++;
            // cout << "cx: " << cx << ", cy: " << cy << endl;
            // cout << "--------------" << endl;
            if(cx == 0 && cy == 0) {
                flag = true;
                result = cnt;
                break;
            }
        }
        if(flag) break;
        result = -1;
    }

    cout << result;

    return 0;
}
