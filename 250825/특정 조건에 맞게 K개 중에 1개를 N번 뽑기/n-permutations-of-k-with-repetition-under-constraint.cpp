#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> comp;
vector<vector<int>> all_comp; // comp쌍 담음

bool IsDuplicated() {
    if (N < 3) return false;
    
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (comp[i] == comp[i - 1]) {
            count++;
            if (count >= 3) return true;
        } else {
            count = 1;
        }
    }
    return false;
}

void MakeSequence() {
    // 모두 선택
    if(comp.size() == N) {
        if(!IsDuplicated()) all_comp.push_back(comp);
        return;
    }

    for(int i = 1; i <= K; i++) {
        comp.push_back(i);
        MakeSequence();
        comp.pop_back();
    }
}

int main() {
    cin >> K >> N;

    MakeSequence();

    for(int i = 0; i < all_comp.size(); i++) {
        for(int j = 0; j < N; j++) {
            cout << all_comp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}