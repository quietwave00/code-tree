#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000

int N, B;
vector<int> prices;

int main()
{
    cin >> N >> B;
    for (int i = 0; i < N; i++)
    {
        int num = 0;
        cin >> num;
        prices.push_back(num);
    }

    sort(prices.begin(), prices.end());

    int max_cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        int bud = B;
        for (int j = 0; j < N; j++)
        {
            int price;
            if (j == i) price = prices[j] / 2;
            else price = prices[j];

            if (bud >= price) {
                bud -= price;
                cnt++;
            }
            else {
                break;
            }
        }
        max_cnt = max(cnt, max_cnt);
    }

    cout << max_cnt << endl;

    return 0;
}