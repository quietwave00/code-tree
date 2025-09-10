#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int N, M;
int arr[20];
vector<int> comp;
int max_xor = 0;

void CalculateXOR() {
    int xor_result = 0;
    for(int i = 0; i < comp.size(); i++) {
        xor_result ^= comp[i];
    }
    max_xor = max(max_xor, xor_result);
}

void Choose(int cur, int cnt) {
    if(cnt == M) {
        CalculateXOR();
        return;
    }
    
    if(cur >= N) {
        return;
    }

    comp.push_back(arr[cur]);
    Choose(cur + 1, cnt + 1);
    comp.pop_back();

    Choose(cur + 1, cnt);
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    Choose(0, 0);
    
    cout << max_xor << endl;

    return 0;
}