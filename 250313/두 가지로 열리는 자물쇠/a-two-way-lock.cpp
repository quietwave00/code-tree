#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr1[3], arr2[3];

bool Minus(int a, int b)
{
    int diff = abs(a - b);
    return diff <= 2 || diff >= N - 2;
}

bool cal(int a1, int b1, int c1)
{
    if (Minus(a1, arr1[0]) && Minus(b1, arr1[1]) && Minus(c1, arr1[2]))
        return true;

    if (Minus(a1, arr2[0]) && Minus(b1, arr2[1]) && Minus(c1, arr2[2]))
        return true;

    return false;
}

int main()
{
    cin >> N;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> arr2[i];
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (cal(i, j, k))
                    cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

// 1 - N(9)
// 1 9 5
// 1 2 3, 4 5 6
// N - 2 = 7
// N - 1 = 8
// N - 2 = 7
