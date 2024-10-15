#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> tuples(n);
    for(int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        tuples[i] = make_tuple(h, -w, i + 1);
    }

    sort(tuples.begin(), tuples.end());

    for(int i = 0; i < n; i++) {
        int h, w, idx;
        tie(h, w, idx) = tuples[i]; 
        printf("%d %d %d\n", h, -w, idx);
    }
    
    return 0;
}