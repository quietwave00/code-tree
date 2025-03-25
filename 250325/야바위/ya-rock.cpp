#include <iostream>
#include <algorithm>
using namespace std;

int N;

int main() {
    cin >> N;

    int max_score = 0;
    int cups[3 + 1] = { 0 };
    for(int i = 1; i <= 3; i++) { // 돌 넣어놓기
        cups[i] = 1;
        int score = 0;

        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        for(int i = 0; i < N; i++) { // N번 시행
            int temp = cups[n1];
            cups[n1] = cups[n2];
            cups[n2] = temp;

            if(cups[n3] == 1) score++;
        }
        max_score = max(score, max_score);  
    }

    cout << max_score << endl;
    
    return 0;
}
// temp;
// temp = arr[0];
// arr[0] = arr[1];
// arr[1] = temp;
// if(arr[2] == 1) score++;