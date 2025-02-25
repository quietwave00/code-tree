#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int S, N, sum;
int arr[100];

int main() {
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int min_num = INT_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(arr[i] + arr[j] == S) continue;

            int result = abs((sum - (arr[i] + arr[j])) - S);
            min_num = min(min_num, result);
        }
    }

    cout << min_num << endl;

    return 0;
}

// N - 2개 => S
// 두 개 선택해서 누적합이랑 빼기