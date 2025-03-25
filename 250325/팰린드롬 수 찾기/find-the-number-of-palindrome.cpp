#include <iostream>
#include <vector>
using namespace std;

int X, Y;

bool Check(int num) {
    vector<int> vec;
    while(num > 0) {
        vec.push_back(num % 10);
        num = num / 10;
    }

    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] != vec[vec.size() - 1 - i]) return false;
    }
    return true;
}

int main() {
    cin >> X >> Y;

    int cnt = 0;
    for(int num = X; num <= Y; num++) {
        if(Check(num)) cnt++;
    }

    cout << cnt << endl;

    return 0;
}

// X <= num <= Y
// 홀수 7개 7 / 2 = 3
// 1 2 3 (4) 5 6 7
// 1 7
// 2 6