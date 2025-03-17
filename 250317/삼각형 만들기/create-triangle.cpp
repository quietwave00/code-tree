#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int arr[100][2];

bool isParallel(int a, int b, int c)
{
    return ((arr[a][1] == arr[b][1]) || (arr[b][1] == arr[c][1]) || (arr[c][1] == arr[a][1]))
            && ((arr[a][0] == arr[b][0]) || (arr[b][0] == arr[c][0]) || (arr[c][0] == arr[a][0]));
}
    int main()
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
            arr[i][0] += 10000;
            arr[i][1] += 10000;
        }

        int max_area = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                for (int k = j + 1; k < N; k++)
                {
                    if (isParallel(i, j, k))
                    {
                        int x1 = arr[i][0], y1 = arr[i][1];
                        int x2 = arr[j][0], y2 = arr[j][1];
                        int x3 = arr[k][0], y3 = arr[k][1];

                        int area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                            max_area = max(area, max_area);
                    }
                }
            }
        }

        cout << max_area << endl;

        return 0;
}

// N개의 점 -> 3개로 삼각형
// x, y축 평행한 삼각형 중 최대 넓이 * 2
// 3개씩 다 잡아보기