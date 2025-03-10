#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr1[100];
int arr2[100];

bool Includes(vector<int>& vec) {
    for (int i = 0; i < M; i++) {
        if (arr2[i] != vec[i]) return false;
    }
    return true;
}

bool heapPermutation(vector<int>& target_copy, int size) {
    if (size == 1) {
        return Includes(target_copy);
    }

    for (int i = 0; i < size; i++) {
        if (heapPermutation(target_copy, size - 1)) { 
            return true;
        }

        if (size % 2 == 1) {
            swap(target_copy[0], target_copy[size - 1]);
        } else {
            swap(target_copy[i], target_copy[size - 1]);
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> arr2[i];
    }

    int cnt = 0;
    for (int i = 0; i <= N - M; i++) {
        vector<int> target(arr1 + i, arr1 + i + M);
        if (heapPermutation(target, M)) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
