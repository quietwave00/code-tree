#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first;
        arr[i].second = i; // 기존 인덱스
    }

    sort(arr.begin(), arr.end());

    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
        result[arr[i].second] = i + 1; // 새로운 인덱스
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}