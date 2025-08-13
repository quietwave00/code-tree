#include <iostream>
#include <vector>
using namespace std;

int N;
int answer;
vector<int> nums;

bool Check() {
    for(int i = 0; i < N; i+=nums[i]) {
        for(int j = i; j < i + nums[i]; j++) {
            if(nums[j] != nums[i]) return false;
        }
    }
    return true;
}

void MakeNum(int cur) {
    if(cur == N + 1) {
        if(Check()) answer++;
        return;
    }

    for(int i = 1; i <= 4; i++) {
        nums.push_back(i);
        MakeNum(cur + 1);
        nums.pop_back();
    }
    return;
}

int main() {
    cin >> N;
    MakeNum(1);

    cout << answer << endl;

    return 0;
}

// 1 ~ 4
// 1. 재귀로 경우의 수 모두 만들기
// 2. 체크하기 -> 반복문으로 체크해야겠다