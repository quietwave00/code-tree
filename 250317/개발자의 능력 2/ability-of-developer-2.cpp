#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int arr[6];
vector<int> vec;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    int min_num = INT_MAX;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            int sum = arr[i] + arr[j];
            vec.push_back(sum);
        }
    }

    sort(vec.begin(), vec.end());

    int idx = vec.size() - 1;
    cout << vec[idx] - vec[idx - 2] << endl;

    return 0;
}
