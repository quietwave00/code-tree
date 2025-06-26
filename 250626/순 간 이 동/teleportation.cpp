#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int A, B, x, y;

int main() {
    cin >> A >> B >> x >> y;

    int min_distance = INT_MAX;

    // 1.
    int distance = abs(A - x) + abs(B - y);
    min_distance = min(distance, min_distance);
    // cout << "1. distance: " << distance << endl;

    // 2.
    distance = abs(A - y) + abs(B - x);
    min_distance = min(distance, min_distance);
    // cout << "2. distance: " << distance << endl;

    // 3.
    distance = abs(A - B);
    min_distance = min(distance, min_distance);
    // cout << "3. distance: " << distance << endl;

    cout << min_distance;

    return 0;
}

// A -> B
// 1. A -> x -> y -> B
// 2. A -> y -> x -> B
// 3. A -> B