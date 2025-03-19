#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

int N, B;
int prices[MAX];

int main()
{
    cin >> N >> B;
    for(int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    int max_cnt = 0;
    for(int i = 0; i < N; i++) { // i = 반값 할인 선택
        int cnt = 0;
        int sum = 0;
        for(int j = 0; j < N; j++) {
            int price;
            if(j == i) {
                price = prices[j] / 2;
                sum += price;
            }
            else {
                price = prices[j];
                sum += price;
            }
            if(sum > B) {
                sum -= price;
                break;
            }
            cnt++;
        }
        max_cnt = max(cnt, max_cnt);
    }
    
    cout << max_cnt << endl;
    


    return 0;
}

// 선물을 다 못 줄 수도 있는 거임...
// P를 순회
// P(i) / 2 후 price >= B일 때까지 cnt++;
// 어떤 P(i)를 선택했는지에 따라 cnt max값 계산
