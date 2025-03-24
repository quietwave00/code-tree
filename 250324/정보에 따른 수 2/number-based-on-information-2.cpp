#include <iostream>
#include <map>
#include <climits>
#include <cmath>

using namespace std;

int T, a, b;
map<int, char> m;

int GetD1(int k) {
    int min_diff = INT_MAX;

    for (auto it : m) {
        if (it.second == 'S') {
            min_diff = min(min_diff, abs(it.first - k));
        }
    }
    return min_diff;
}

int GetD2(int k) {
    int min_diff = INT_MAX;

    for (auto it : m) {
        if (it.second == 'N') {
            min_diff = min(min_diff, abs(it.first - k));
        }
    }
    return min_diff;
}

int main() {
    cin >> T >> a >> b;

    for (int i = 0; i < T; i++) {
        char c;
        int x;
        cin >> c >> x;
        m[x] = c;
    }

    int cnt = 0;
    for (int i = a; i <= b; i++) { // k 기준
        int d1 = GetD1(i);
        int d2 = GetD2(i);

        if (d1 <= d2) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
