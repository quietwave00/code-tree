#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N, H, T;
int arr[100];

int main()
{
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int min_num = INT_MAX;
    for (int s = 0; s < 99 - (T - 1); s++)
    {
        for (int e = s + 2; e < 99; e++)
        {
            if (arr[s] == 0 || arr[e] == 0)
                continue;

            int sum_h = 0;
            for (int i = s; i <= e; i++)
            {
                sum_h += abs(H - arr[i]);
            }
            if(sum_h > 0) {
                min_num = min(sum_h, min_num);
            }
        }
    }

    cout << min_num << endl;

    return 0;
}

// 개수, 높이, 연속개수
// 연속개수 구간 정하기
// 0~2, 1~3, 2~4, ... (MAX - 1) - (T - 1) ~ MAX - 1