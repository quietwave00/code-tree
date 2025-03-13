#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[6];
int sum;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
        sum += arr[i]; 
    }

    int min_diff = INT_MAX;
    for(int i = 0; i < 6; i++) {
        for(int j = i + 1; j < 6; j++) {
            for(int k = j + 1; k < 6; k++) {
                int num = arr[i] + arr[j] + arr[k];
                min_diff = min(abs(num - (sum - num)), min_diff);
            }
        }
    }

    cout << min_diff << endl;

    return 0;
}