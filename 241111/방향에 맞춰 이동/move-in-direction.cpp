#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    int n;
    cin >> n;

    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        char dir; int num;
        cin >> dir >> num;

        if(dir == 'E') {
            x = x + dx[0] * num;
            y = y + dy[0] * num;
        }
        else if(dir == 'S') {
            x = x + dx[1] * num;
            y = y + dy[1] * num;
        }
        else if(dir == 'W') {
            x = x + dx[2] * num;
            y = y + dy[2] * num;
        }
        else if(dir == 'N') {
            x = x + dx[3] * num;
            y = y + dy[3] * num;
        }
    }

    cout << x << " " << y;

    return 0;
}