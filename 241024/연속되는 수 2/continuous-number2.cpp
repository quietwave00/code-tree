#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    int max_count = 1;
    int current_count = 1;

    for (int i = 1; i < N; ++i) {
        if (numbers[i] == numbers[i - 1]) {  // 이전 숫자와 같으면
            current_count++;
        } else {
            max_count = max(max_count, current_count);
            current_count = 1;
        }
    }

    max_count = max(max_count, current_count);

    cout << max_count << endl;

    return 0;
}