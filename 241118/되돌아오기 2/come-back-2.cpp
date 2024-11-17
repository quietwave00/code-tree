#include <iostream>
#include <string>

using namespace std;

// 동남서북
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dir;

int getDir(char ch) {
    switch(ch) {
        case 'F': break;
        case 'R': dir = (dir + 1) % 4; break;
        case 'L': dir = (dir + 3) % 4; break;
    }
    return dir;
}

int main() {
    string str;
    cin >> str;
    
    dir = 3; // start direction
    int cx = 0, cy = 0, cnt = 0, answer = -1;
    bool flag = false;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        dir = getDir(ch);

        if(ch == 'F') {
            cx = cx + dx[dir];
            cy = cy + dy[dir];    
        }
        cnt++;
        // cout << "cx: " << cx << ", cy: " << cy << endl;

        if(cx == 0 && cy == 0) {
            flag = true;
            answer = cnt;
            break;
        }

        if(!flag) {
            answer = -1;
        }
    }

    cout << answer;
    
    return 0;
}