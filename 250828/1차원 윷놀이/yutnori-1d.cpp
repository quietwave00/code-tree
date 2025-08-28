#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, K, max_score;
vector<int> nums;
vector<int> comp; // 말 순서 조합
vector<int> board; // idx:말, value: 위치

int GetScore() {
    // for(int i = 0; i < N; i++) {
    //     cout << comp[i] << " ";
    // }
    // cout << endl;
    board.assign(K + 1, 0);

    int score = 0;
    for(int i = 0; i < N; i++) {
        if(board[comp[i]] == M) continue;
        board[comp[i]] += nums[i];
        if(board[comp[i]] >= M) {
            score++;
        }
    }
    // cout << "score: " << score << endl;
    return score;
}

void Choose(int cnt) {
    if(cnt == N + 1) {
        max_score = max(GetScore(), max_score);
        return;
    }

    for(int i = 1; i <= K; i++) {
        comp.push_back(i);
        Choose(cnt + 1);
        comp.pop_back();
    }
}


int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Choose(1);

    cout << max_score << endl;

    return 0;
}

/*
1~M
K개 말
N번의 턴
말이 M에 도달하면 1점(도달한 말 재선택 가능, 그러나 움직이지 않음)
최대값 구하기

1. 말 선택: 1~K까지 중복하여 N개 선택
2. 말 이동: 선택된 말은 N번에 걸쳐
if(pos != M) pos+=nums[N]
if(pos >= M) score++;
*/
