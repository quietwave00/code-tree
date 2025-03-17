#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N = 0;
int arr[1000][1000];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    int min_diff = INT_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int diff = pow(abs(arr[i][0] - arr[j][0]), 2) + pow(abs(arr[i][1] - arr[j][1]), 2);
            min_diff = min(min_diff, diff);
        }
    }

    cout << min_diff << endl;

    return 0;
}

// 가장 가까운 거리에 위치한 두 점 찾기
// 두 점끼리 모두 잡아보고 제곱값
// 최솟값 출력