#include <iostream>
#include <string>

using namespace std;

// 동 남 서 북
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    string cmd;
    cin >> cmd;

    int dir_num = 3;
    int x = 0, y = 0;
    for(int i = 0; i < cmd.length(); i++) {
        char dir = cmd[i];

        if(dir == 'L') {
            dir_num = (dir_num - 1 + 4) % 4;
        }

        else if(dir == 'R') {
            dir_num = (dir_num + 1) % 4;
        }

        else if(dir == 'F') {
            x += dx[dir_num];
            y += dy[dir_num];
        }
    }

    cout << x << " " << y;

    return 0;
}