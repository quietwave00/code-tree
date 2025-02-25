#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[100];

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int max_sum = 0;
    for(int i = 0; i <= N - K; i++) {
        int sum = 0;
        for(int j = i; j < i + K; j++) {
            sum += arr[j];
        }
        max_sum = max(sum, max_sum);
    }
    
    cout << max_sum << endl;
    
    return 0;
}