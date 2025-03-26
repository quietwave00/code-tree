#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;

int main() {
    cin >> A >> B >> C;

    int max_num = 0;
    int a_cnt = -1;
    while(true) {
        int b_cnt = -1;
        a_cnt++;
        while(true) {
            b_cnt++;
            int sum = A * a_cnt + B * b_cnt;
            if(sum <= C) max_num = max(sum, max_num);
            else break;
        }
        if(A * a_cnt > C) break;       
    }

    cout << max_num << endl;
    
    return 0;
}

// A, B, C
// num <= C 
// Max