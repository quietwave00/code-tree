#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int line[101] = { 0 };
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        for(int j = a; j < b; j++) {
            line[j]++;
        }
    }

    

    int cnt = 0;
    for(int i = 1; i <= 101; i++) {
        if(line[i] >= 2) cnt++;
    }

    cout << cnt << '\n';
    
    return 0;
}