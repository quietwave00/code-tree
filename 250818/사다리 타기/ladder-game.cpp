#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<tuple<int, int, int>> line;
vector<int> comp, target_pos;
int min_cnt = INT_MAX;

vector<int> GetOrdering() {
    vector<int> ordering(N);
    for(int i = 0; i < N; i++) {
        ordering[i] = i + 1;
    }
    
    vector<int> selected_lines = comp;
    
    sort(selected_lines.begin(), selected_lines.end(), [](int a, int b) {
        return get<2>(line[a]) < get<2>(line[b]);
    });
    
    for(int idx : selected_lines) {
        int a1 = get<0>(line[idx]);
        int a2 = get<1>(line[idx]);
        swap(ordering[a1], ordering[a2]);
    }
    
    return ordering;
}

void Choose(int cur) {
    vector<int> ordering = GetOrdering();
    if(equal(target_pos.begin(), target_pos.end(), ordering.begin())) {
        min_cnt = min(min_cnt, (int) comp.size());
    }
    
    if(cur == M) {
        return;
    }
    
    comp.push_back(cur);
    Choose(cur + 1);
    comp.pop_back();
    
    Choose(cur + 1);
}

void SetTargetPosition() {
    target_pos.resize(N);
    for(int i = 0; i < N; i++) {
        target_pos[i] = i + 1;
    }
    
    vector<int> all_lines;
    for(int i = 0; i < M; i++) {
        all_lines.push_back(i);
    }
    
    sort(all_lines.begin(), all_lines.end(), [](int a, int b) {
        return get<2>(line[a]) < get<2>(line[b]);
    });
    
    for(int idx : all_lines) {
        int a1 = get<0>(line[idx]);
        int a2 = get<1>(line[idx]);
        swap(target_pos[a1], target_pos[a2]);
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        line.push_back(make_tuple(num1 - 1, num1, num2));
    }
    
    SetTargetPosition();
    Choose(0);
    
    cout << min_cnt << endl;

    return 0;
}