#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100][3 + 1];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> arr[i][j];
        }
    }

    int max_score = 0;
    for(int i = 1; i <= 3; i++) { // 돌 넣어놓기
        int cups[3 + 1] = { 0 };
        cups[i] = 1;
        int score = 0;

        for(int j = 1; j <= N; j++) { // N번 시행
            int n1 = arr[j][1];
            int n2 = arr[j][2];
            int n3 = arr[j][3];

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