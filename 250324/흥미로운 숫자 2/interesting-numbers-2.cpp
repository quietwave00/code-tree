#include <iostream>
#include <set>

using namespace std;

int X, Y;

bool IsInterestedNumber(int num) {
    set<int> s;
    while(num > 0) {
        int digit = num % 10;
        s.insert(digit);
        num /= 10;
    }
    if(s.size() == 2) return true;
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
// 각 자리수 분해 후 set쓰면 되남 사이즈 2일 때만 return true