#include <iostream>
using namespace std;

int N;
int arr[101];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        
        for(int j = num1; j <= num2; j++) {
            arr[j] += 1;
        }
    }

    bool overlap = false;
    for(int i = 1; i <= 100; i++) {
        if(arr[i] == 3) overlap = true;
    }

    if(overlap) cout << "Yes";
    else cout << "No";

    
    return 0;
}

// 모두 겹치는 지점 있는지