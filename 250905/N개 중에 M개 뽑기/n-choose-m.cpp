#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> comp;

void Print() {
    for (int i = 0; i < M; i++) {
        cout << comp[i] << " ";
    }
    cout << endl;
}

void Choose(int pos, int start) {
    if (pos == M) {
        Print();
        return;
    }
    for (int num = start; num <= N; num++) {
        comp.push_back(num);
        Choose(pos + 1, num + 1);
        comp.pop_back();
    }
}

int main() {
    cin >> N >> M;
    Choose(0, 1);
    return 0;
}
/*
1~N 중 M개 뽑을 시 조합
*/