#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int arrA[100];
int arrB[100];


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arrA[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> arrB[i];
    }

    int num = 0;
    for(int i = N - 1; i > 0; i--) {
        // printf("arrB[i]: %d, arrA[i]: %d\n", arrB[i], arrA[i]);
        if(arrB[i] > arrA[i]) { // 옮겨야 하는 경우
            num += arrB[i] - arrA[i];
            arrA[i - 1] -= arrB[i] - arrA[i];
        }
    }

    cout << num << endl;

    return 0;
}

// 5 4 3 1
// 3 2 3 5

// 1.
// 5 4 -1 5
// 3 2  3 5

// 2.
// 5 0 3 5
// 3 2 3 5

// 3.
// 3  2 3 5
// 3  2 3 5
