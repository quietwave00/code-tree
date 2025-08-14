#include <iostream>
#include <vector>
using namespace std;

int N, answer;
pair<int, int> line[15];
vector<int> comp;

bool IsOverlap() {
    int check[1000] = { 0 };
    for(int i = 0; i < comp.size(); i++) {
        for(int j = line[comp[i]].first; j <= line[comp[i]].second; j++) {
            check[j]++;
            if(check[j] > 1) return true;
        }
    }
    return false;
}

void Choose(int cur) {
    if(!comp.empty()) {
        if(!IsOverlap()) {
            answer = max((int)comp.size(), answer);
        }
    }
    if(cur == N) {
        return;
    }

    for(int i = 0; i < N; i++) {
        comp.push_back(i);
        Choose(cur + 1);
        comp.pop_back();
    }
    return;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        line[i] = make_pair(a, b);
    }

    Choose(0);

    cout << answer << endl;

    return 0;
}

// 주어진 영역에서 겹치지 않게 선택...
// 하나씩 다 조합해보고 겹치는지 안 겹치는지 체크. 겹치면 return false;
// 그리고 cnt구한 후 max계산하면 될듯!!