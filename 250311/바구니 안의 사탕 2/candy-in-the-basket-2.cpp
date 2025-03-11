#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, K;
map<int, int> m;

bool Includes(int x) {
    return x >= 0 && x <= 100;
}

int main() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int num1 = 0, num2 = 0;
        cin >> num1 >> num2;
        m[num2] += num1;
    }

    int max_num = 0;
    for(int i = 0; i <= 100; i++) {
        int sum = 0;
            for(int j = i - K; j <= i + K; j++) {
                sum += m[j];
                max_num = max(sum, max_num);
        }
    }

    cout << max_num << endl;
    
    return 0;
}