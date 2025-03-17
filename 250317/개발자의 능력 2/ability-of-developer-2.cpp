#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int arr[6];

int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    int min_diff = INT_MAX;
    int sum1 = 0, sum2 = 0;
    // 첫 번째
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            sum1 = arr[i] + arr[j];
            // 두 번째
            for(int k = 0; k < 6; k++) {
                if (k == i || k == j) continue;
                for(int l = k + 1; l < 6; l++) {
                    if(l == i || l == j) continue;
                    sum2 = arr[k] + arr[l];

                    int nums[6] = {0};
                    nums[i] = 1; nums[j] = 1; nums[k] = 1; nums[l] = 1;

                    // 세 번째
                    int sum3 = 0;
                    for (int m = 0; m < 6; m++)
                    {
                        if (!(nums[m] == 1))
                        {
                            sum3 += arr[m];
                        }
                    }
                    vector<int> sums;
                    sums.push_back(sum1);
                    sums.push_back(sum2);
                    sums.push_back(sum3);

                    // printf("%d %d %d\n", sum1, sum2, sum3);

                    sort(sums.begin(), sums.end());

                    int diff = sums[2] - sums[0];
                    min_diff = min(diff, min_diff);
                }
            }
        }
    }

    cout << min_diff << endl;

    return 0;
}
