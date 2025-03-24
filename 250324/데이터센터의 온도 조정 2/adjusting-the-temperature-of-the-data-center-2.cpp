#include <iostream>
#include <algorithm>

#define MAX_TEMP 1000

using namespace std;

int N, C, G, H;
pair<int, int> arr[1000];
int temp;

int GetAmount(int t1, int t2) {
    if(temp < t1) return C;
    else if(temp >= t1 && temp <= t2) return G;
    else return H;
}

int main() {
    cin >> N >> C >> G >> H;
    for(int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    int max_amount = 0;
    for(int i = 0; i <= MAX_TEMP; i++) {
        int total_amount = 0;
        for(int j = 0; j < N; j++) {
            temp = i;
            total_amount += GetAmount(arr[j].first, arr[j].second);
            max_amount = max(total_amount, max_amount);
        }
    }

    cout << max_amount << endl;

    return 0;
}

// t < T1: C
// T1 <= t <= T2: G
// T2 < t: H
