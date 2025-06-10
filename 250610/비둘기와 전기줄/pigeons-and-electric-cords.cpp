#include <iostream>
using namespace std;

int N, cnt;
int bird[100];

int main() {
    for (int i = 0; i < 100; ++i) {
        bird[i] = 2;
    }
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num; bool location;
        cin >> num >> location;
        if(bird[num] != 2 && bird[num] != location) {
            cnt++;
        }
        bird[num] = location;
    }

    cout << cnt << endl;
    
    return 0;
}