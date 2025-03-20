#include <iostream>
using namespace std;

int K, N;
int arr[20][10];

bool Check(int a, int b) {
    for (int times = 0; times < K; times++) {
        if (arr[a][times] < arr[b][times]) continue;
        else return false;
    }
    return true;
}

int main()
{
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            arr[num - 1][i] = j; // [dev][times] = rank
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            if (Check(i, j)) cnt++;
        }
    }

    cout << cnt << endl;;

    return 0;
}
