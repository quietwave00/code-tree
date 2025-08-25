#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

string str;
int max_num = INT_MIN;
vector<int> comp;

int GetResult() {
    int result = comp[0];
    int comp_idx = 1;
    
    for(int i = 1; i < str.length(); i += 2) {
        char op = str[i];
        int next_num = comp[comp_idx++]; 
        
        if(op == '+') {
            result += next_num;
        }
        else if(op == '-') {
            result -= next_num;
        }
        else if(op == '*') {
            result *= next_num;
        }
    }
    return result;
}

void Choose(int pos) {
    if(pos >= str.length()) {
        int result = GetResult();
        max_num = max(result, max_num);
        return;
    }
    
    if(pos % 2 == 1) {
        Choose(pos + 1);
        return;
    }
    
    for(int num = 1; num <= 4; num++) {
        comp.push_back(num);
        Choose(pos + 1);
        comp.pop_back();
    }
}

int main() {
    cin >> str;
    Choose(0);
    cout << max_num << endl;
    return 0;
}

// N길이: a~f, +-*
//알파벳에 1~4 대입하여 최댓값