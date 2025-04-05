#include <iostream>
using namespace std;

int N, T;
int top[200];
int bottom[200];

int main() {
    cin >> N >> T;
    for(int i = 0; i < N; i++) cin >> top[i];
    for(int i = 0; i < N; i++) cin >> bottom[i];

    while(T--) {
        // top
        int temp = top[N - 1];

        for(int i = N - 1; i > 0; i--) {
            top[i] = top[i - 1];
        }
        top[0] = bottom[N - 1]; 

        // bottom
        for(int i = N - 1; i > 0; i--) {
            bottom[i] = bottom[i - 1];
        }
        bottom[0] = temp;
    }

    for(int i = 0; i < N; i++) cout << top[i] << " ";
    cout << endl;
    for(int i = 0; i < N; i++) cout << bottom[i] << " ";
    
    return 0;
}

