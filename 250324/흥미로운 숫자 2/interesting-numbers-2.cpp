#include <iostream>
#include <map>

using namespace std;

int X, Y;

bool IsInterestedNumber(int num) {
    map<int, int> m;
    while(num > 0) {
        int digit = num % 10;
        m[digit]++;
        num /= 10;
    }
    if(m.size() != 2) return false;
    for(int i = 0; i < m.size(); i++) {
        if(m[i] == 1) return true;
    }
    return false;
}

int main() {
    cin >> X >> Y;

    int cnt = 0;
    for(int i = X; i <= Y; i++) {
        if(IsInterestedNumber(i)) cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}

// X <= num <= Y
// a a b a ... 
// 각 자리수 분해 후 map에 빈도수 체크