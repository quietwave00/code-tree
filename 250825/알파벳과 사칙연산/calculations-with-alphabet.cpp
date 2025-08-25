#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

string str;
int max_num = INT_MIN;
vector<int> comp;
vector<char> alpha;
map<char,int> idx_map; // 알파벳 -> comp

int GetResult() {
    int result = comp[idx_map[str[0]]];
    for (int i = 1; i < str.length(); i += 2) {
        char op = str[i];
        int next_num = comp[idx_map[str[i+1]]];
        
        if (op == '+') result += next_num;
        else if (op == '-') result -= next_num;
        else if (op == '*') result *= next_num;
    }
    return result;
}

void Choose() {
    if (comp.size() == alpha.size()) {
        int result = GetResult();
        max_num = max(result, max_num);
        return;
    }
    
    for (int num = 1; num <= 4; ++num) {
        comp.push_back(num); 
        Choose();
        comp.pop_back();
    }
}

int main() {
    cin >> str;

    for (char c : str) {
        if (idx_map.find(c) == idx_map.end()) {
            idx_map[c] = alpha.size();
            alpha.push_back(c);
        }
    }

    Choose();
    cout << max_num << endl;
    return 0;
}
