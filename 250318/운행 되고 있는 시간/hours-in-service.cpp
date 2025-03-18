#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int arr[100][2];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    // 해고
    int min_cnt = INT_MAX;
    for(int i = 0; i < N; i++) {
        int counting[1000] = {};
        for(int j = 0; j < N; j++) {
            if(j == i) continue;

            int x1 = arr[j][0], x2 = arr[j][1];
            for(int k = x1; k <= x2; k++) counting[k]++;
        }

        int cnt = 0;
        for(int j = 0; j < 1000; j++) {
            if(counting[j] > 0) cnt++;
        }
        min_cnt = min(cnt, min_cnt);
        
    }

    cout << min_cnt << endl;

    return 0;
}

// N명 -> 한명 해고
// 선분 구간이라 생각하면 되겠다
// 한 명씩 다 해고시켜 보기 -> 겹치는 구간이 제일 적은 경우
