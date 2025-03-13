#include <iostream>
#include <cmath>
using namespace std;

int N;
int given[3];

int main()
{
    cin >> N;
    for (int i = 0; i < 3; i++)
    {
        cin >> given[i];
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                // printf("i: %d, j: %d, k: %d\n", i, j, k);
                if(abs(i - given[0]) <= 2 || abs(j - given[1]) <= 2 || abs(k - given[2]) <= 2) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

// 1 2 3
// 5 4 6