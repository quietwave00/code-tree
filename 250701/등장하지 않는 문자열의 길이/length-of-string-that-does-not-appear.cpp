#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string str;

bool Check(string target) {
    int length = target.length();

    int cnt = 1;
    for(int i = length; i < N; i++) {
        string comp;
        for(int j = 0; j < length; j++) {
            comp += str[i + j];
        }
        // cout << "target: " << target << ", comp: " << comp << endl;
        if(target == comp) cnt++;
    }
    if(cnt >= 2) return true;
    return false;
}

int main() {
    cin >> N;
    cin >> str;

    int min_length = INT_MAX;
    // 길이별
    for(int length = 1; length <= N; length++) {
        string target;
        for(int i = 0; i < length; i++) {
            target += str[i];
        }
        // cout <<"****target: " << target << endl;
        if(!Check(target)) min_length = min(length, min_length);
    }

    cout << min_length << endl;

    return 0;
}

// 길이별 문자열
// 2번 이상 나타나면 false 처리
// A B C D A B C