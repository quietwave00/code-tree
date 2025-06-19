#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, p;
char c[101];
int u[101];

int main()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i] >> u[i];
    }

    if (u[p] > 0)
    {
        int arr[101];
        int people[n];
        for (int i = 0; i < n; i++)
        {
            people[i] = 1; // 가능성 O으로 시작
        }

        for (int i = p; i <= m; i++)
        {
            if (u[i] > 0)
            {
                people[c[i] - 'A'] = 0; // 가능성X
            }

            for(int j = i; j > 1; j--) {
                if (u[j] == u[j - 1])
                {
                    people[c[j - 1] - 'A'] = 0;
                } else break;
            }
            
        }

        vector<char> unread;
        for (int i = 0; i < n; i++)
        {
            if (people[i] == 1)
            {
                unread.push_back('A' + i);
            }
        }

        sort(unread.begin(), unread.end());

        for (char name : unread)
        {
            cout << name << " ";
        }
    } else cout << "";

    return 0;
}

// 사람 수 N -> ABCD,..., 정보 수 M, 메시지 번호 p
// 사람번호c, u unread