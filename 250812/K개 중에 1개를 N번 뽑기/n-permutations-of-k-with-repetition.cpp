#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> nums;

void Print() {
    for(int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
}

void Choose(int cur) {
    if(cur == N + 1) {
        Print();
        return;
    }

    for(int select = 1; select <= K; select++) {
        nums.push_back(select);
        Choose(cur + 1);
        nums.pop_back();
    }

    return;
}

int main() {
    cin >> K >> N;
    Choose(1);
    
    return 0;
}