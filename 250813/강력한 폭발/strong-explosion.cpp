#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt, answer;
int arr[20][20];
vector<pair<int,int>> bombs; 
vector<int> dirs;

int dir[3][4][2] = {
    {{2, 0}, {1, 0}, {-1, 0}, {-2, 0}},
    {{1, 0}, {0, 1}, {-1, 0}, {0, -1}},
    {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}}
};

bool InRange(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

void Check() {
    vector<vector<int>> visited(N, vector<int>(N, 0));
    int bomb_cnt = 0;

    for (int k = 0; k < bombs.size(); k++) {
        int x = bombs[k].first;
        int y = bombs[k].second;
        int type = dirs[k];

        if (!visited[x][y]) {
            visited[x][y] = 1;
            bomb_cnt++;
        }

        for (int j = 0; j < 4; j++) {
            int nx = x + dir[type][j][0];
            int ny = y + dir[type][j][1];
            if (InRange(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                bomb_cnt++;
            }
        }
    }
    answer = max(answer, bomb_cnt);
}

void Check(int cur) {
    if (cur == bombs.size()) {
        Check();
        return;
    }

    for (int t = 0; t < 3; t++) {
        dirs.push_back(t);
        Check(cur + 1);
        dirs.pop_back();
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                bombs.push_back({i, j});
            }
        }
    }

    Check(0);

    cout << answer << endl;
    return 0;
}