#include <iostream>
#include <algorithm>

using namespace std;

int N;
int pos;
int max_pos;
char arr[101];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> pos;
        cin >> arr[pos];

        max_pos = max(pos, max_pos);
    }

    int max_num = 0;
    for (int s = 0; s <= max_pos - 1; s++)
    {
        for (int e = s + 1; e <= max_pos; e++)
        {
            if(arr[s] == 0 || arr[e] == 0) continue;
            int G_cnt = 0, H_cnt = 0;
            for (int i = s; i <= e; i++)
            {
                if (arr[i] == 'G')
                    G_cnt++;
                if (arr[i] == 'H')
                    H_cnt++;
            }

            if ((G_cnt != 0 && H_cnt != 0) && G_cnt == H_cnt)
            {
                // printf("start: %d, end: %d, G_cnt: %d, H_cnt: %d\n", s, e, G_cnt, H_cnt);
                max_num = max(e - s, max_num);
            }
            if ((G_cnt == 0 && H_cnt > 1) || (H_cnt == 0 && G_cnt > 1))
            {
                // printf("start: %d, end: %d, G_cnt: %d, H_cnt: %d\n", s, e, G_cnt, H_cnt);
                max_num = max(e - s, max_num);
            }
            // cout << "=============" << endl;
        }
    }

    cout << max_num << endl;

    return 0;
}

// 0~1, 0~2, 0~3, ... 0~100
// 1~2, 1~3, 1~4, ... 1~100
// 2~3, 2~4, 2~5, ... 2~100
// 99~100