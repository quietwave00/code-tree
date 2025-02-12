#include <iostream>
#include <algorithm>

using namespace std;

int n;
int numbers[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int max_num = 0;
    for(int i = 0; i < n; i++) {        
        for(int j = i + 2; j < n; j++) {
            int num = numbers[i] + numbers[j];
            // cout << "numbers[i]: " << numbers[i] << ", numbers[j]: " << numbers[j] << endl;
            max_num = max(num, max_num);
        }
    }

    cout << max_num << endl;

    return 0;
}