#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string str;

bool isDuplicated(int length) {
    for(int i = 0; i < N - length; i++) {
        string target = str.substr(i, length);
        for(int j = i + 1; j < N; j++) {
            string comp = str.substr(j, length);
            // printf("target: %s, comp: %s\n", target.c_str(), comp.c_str());
            if(target == comp) return true;
        }
    }
    return false;
}

int main() {
    cin >> N;
    cin >> str;

    int min_length = INT_MAX;
    // 길이별
    for(int length = 1; length <= N; length++) {
        if(!isDuplicated(length)) min_length = min(length, min_length);
    }

    cout << min_length << endl;

    return 0;
}

// 길이별 문자열
// 2번 이상 나타나면 false 처리
