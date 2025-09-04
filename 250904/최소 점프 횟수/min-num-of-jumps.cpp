#include <iostream>
#include <climits>
using namespace std;

int N;
int arr[10];
int min_cnt = INT_MAX;

void Jump(int idx, int cnt) {
    if(idx == N - 1) {
        min_cnt = min(min_cnt, cnt);
        return;
    }
    
    if(idx >= N) {
        return;
    }
    
    if(arr[idx] == 0) {
        return;
    }
    
    for(int i = 1; i <= arr[idx]; i++) {
        Jump(idx + i, cnt + 1);
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    Jump(0, 0);
    
    if(min_cnt == INT_MAX) cout << -1 << endl;
    else cout << min_cnt << endl;
    
    return 0;
}
/*
N 개 정수 
1 -> N 도달하기 위한 최소 점프 횟수
불가하면 -1
arr[i]만큼 반복하면서 재귀
멈추는 조건
1. idx == N - 1; N 도달함
2. idx >= N; 범위 넘어감
3. arr[idx] == 0 점프 불가
*/ 