#include <iostream>
using namespace std;

#define OFFSET 1000000

int N;
int arr[100][2]; // (arr[a][0], 0) (arr[a][1], 1)

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        // arr[i][0] += OFFSET;
        // arr[i][1] += OFFSET;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    { // 선분 선택
        for (int j = 0; j < N; j++)
        { // 나머지
            if (i == j)
                continue;

            int cur_x1 = arr[i][0], cur_x2 = arr[i][1];
            int target_x1 = arr[j][0], target_x2 = arr[j][1];
            // printf("cur_x1: %d, cur_x2: %d, target_x1: %d, target_x2: %d\n", cur_x1, cur_x2, target_x1, target_x2);
            // x 범위 체크
            if((cur_x1 < target_x1 && cur_x2 > target_x2) || (cur_x1 > target_x1 && cur_x2 < target_x2))
            {
                cnt++;
                break;
            }
        }
        // cout << "============" << endl;
    }

    cout << N - cnt << endl;

    return 0;
}