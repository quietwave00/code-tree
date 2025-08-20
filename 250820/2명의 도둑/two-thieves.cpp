#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, C;
int arr[10][10];
vector<int> comp; // 선택한 행
int max_value;

bool IsMaximum(int sum, int value) {
    if(sum + value > C) return true;
    return false;
}

int GetValue() {
    int row1 = comp[0];
    int row2 = comp[1];

    // printf("row1: %d, row2: %d\n", row1, row2);

    int thief1 = 0, thief2 = 0;
    if(row1 == row2) {
        for(int i = 0; i + 2*M <= N; i++) {
            int sum1 = 0, value1 = 0;
            for(int idx = i; idx < i + M; idx++) {
                if(!IsMaximum(sum1, arr[row1][idx])) {
                    sum1 += arr[row1][idx];
                    value1 += pow(arr[row1][idx], 2);
                }
            }

            for(int j = i + M; j + M <= N; j++) {
                int sum2 = 0, value2 = 0;
                for(int idx = j; idx < j + M; idx++) {
                    if(!IsMaximum(sum2, arr[row2][idx])) {
                        sum2 += arr[row2][idx];
                        value2 += pow(arr[row2][idx], 2);
                    }
                }
                thief1 = max(thief1, value1);
                thief2 = max(thief2, value2);
            }
        }
    }
    else {
        for(int i = 0; i + M <= N; i++) {
            int sum1 = 0, value1 = 0;
            for(int idx = i; idx < i + M; idx++) {
                if(!IsMaximum(sum1, arr[row1][idx])) {
                    sum1 += arr[row1][idx];
                    value1 += pow(arr[row1][idx], 2);
                }
            }
            thief1 = max(thief1, value1);
        }

        for(int i = 0; i + M <= N; i++) {
            int sum2 = 0, value2 = 0;
            for(int idx = i; idx < i + M; idx++) {
                if(!IsMaximum(sum2, arr[row2][idx])) {
                    sum2 += arr[row2][idx];
                    value2 += pow(arr[row2][idx], 2);
                }
            }
            thief2 = max(thief2, value2);
        }
    }
    return thief1 + thief2;
}

void Choose(int cur) {
    if(comp.size() == 2) {
        int value = GetValue();
        max_value = max(value, max_value);
        return;
    }

    if(cur == N) {
        return;
    }

    comp.push_back(cur);
    Choose(cur);
    comp.pop_back();

    Choose(cur + 1);
}

int main() {
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    Choose(0);

    cout << max_value << endl;

    return 0;
}

// N x N, M개, 최대 무게 C, 가치 = W^2
// 두 도둑이 선택할 수 있는 열 모두 조합(중복 가능)