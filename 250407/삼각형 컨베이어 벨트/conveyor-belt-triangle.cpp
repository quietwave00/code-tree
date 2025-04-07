#include <iostream>
using namespace std;

int N, T;
int arr1[200];
int arr2[200];
int arr3[200];

int main() {
    cin >> N >> T;
    for(int i = 0; i < N; i++) {
        cin >> arr1[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> arr2[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> arr3[i];
    }

    while(T--) {
        int temp1 = arr1[N - 1];
        int temp2 = arr2[N - 1];

        for(int i = N - 1; i > 0; i--) {
            arr1[i] = arr1[i - 1];
        }
        arr1[0] = arr3[N - 1];

        for(int i = N - 1; i > 0; i--) {
            arr2[i] = arr2[i - 1];
        }
        arr2[0] = temp1;

        for(int i = N - 1; i > 0; i--) {
            arr3[i] = arr3[i - 1];
        }
        arr3[0] = temp2;
    }

    for(int i = 0; i < N; i++) cout << arr1[i] << " ";
    cout << endl;
    for(int i = 0; i < N; i++) cout << arr2[i] << " ";
    cout << endl;
    for(int i = 0; i < N; i++) cout << arr3[i] << " ";

    return 0;
}

// 1 2 4
// 5 9 3
// 6 5 1
// temp1 = 4 -> arr2[0]
// temp2 = 3 -> arr3[0]