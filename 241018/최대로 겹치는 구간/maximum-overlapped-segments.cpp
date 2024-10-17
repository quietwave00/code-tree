#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[201] = { 0 };
    vector<pair<int, int>> vec;
    int flag = false;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if(a < 0 || b < 0) flag = true;
        vec.push_back(make_pair(a, b));
    }

    // offset 작업
    if(flag) {
        int min = 0;
        for(int i = 0; i < n; i++) {
            if(vec[i].first < min) {
                min = vec[i].first;
            }
        }

        int offset = -min;
        for(int i = 0; i < n; i++) {
            vec[i].first += offset;
            vec[i].second += offset;
        }
    }
    
    // 구간 색칠
    for(int i = 0; i < n; i++) {
        for(int j = vec[i].first; j < vec[i].second; j++) {
            arr[j]++;
        }
    }

    int max = 0;
    for(int i = 1; i <= 200; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    cout << max << '\n';
    
    return 0;
}