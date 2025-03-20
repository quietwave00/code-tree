#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[100];

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int max_num = -1;
    for (int target = 0; target < N - (K - 1); target++) {
        int check[1000] = { 0 };
        for (int i = target; i <= target + K; i++) {
            check[arr[i]]++;
        }
        for (int i = 0; i < 1000; i++) {
            if(check[i] >= 2) max_num = max(i, max_num);
        }
    }

    cout << max_num << endl;

    return 0;
}

// 폭탄 N개, K씩 범위 잡아보기, 범위 안에 같은 번호 있는지 체크, max값 update
