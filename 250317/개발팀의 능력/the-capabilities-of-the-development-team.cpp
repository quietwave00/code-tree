#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int arr[5];
int total_sum;

int main()
{
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }

    int min_diff = INT_MAX;
    // 첫 번째 팀
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            // 두 번째 팀
            for(int k = 0; k < 5; k++) {
                if(k == i || k == j) continue;
                for(int l = k + 1; l < 5; l++) {
                    if(l == i || l == j) continue;

                    int sum1 = arr[i] + arr[j];
                    int sum2 = arr[k] + arr[l];
                    int sum3 = total_sum - (sum1 + sum2);

                    // printf("%d %d %d\n", sum1, sum2, sum3);

                    if(sum1 == sum2 || sum1 == sum3 || sum2 == sum3) continue;

                    vector<int> vec;
                    vec.push_back(sum1); vec.push_back(sum2); vec.push_back(sum3);
                    sort(vec.begin(), vec.end());

                    // printf("max: %d, min: %d\n", vec[2], vec[0]);

                    min_diff = min(vec[2] - vec[0], min_diff);
                }
            }
        }
    }

    if(min_diff == INT_MAX) cout << -1 << endl;
    else cout << min_diff << endl;

    return 0;
}

// 5명
// 1 team of 2
// 1 team of 2
// 1 team of 1
// -> 능력치 동일하면 pass
// 능력 차이 최소로
