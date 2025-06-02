#include <iostream>
using namespace std;

int a, b, c, d;
int arr[101];

int main() {
    cin >> a >> b >> c >> d;

    for (int i = a; i < b; i++) arr[i]++;
    for (int i = c; i < d; i++) arr[i]++;

    int cleaned = 0;
    for (int i = 0; i < 100; i++) {
        if (arr[i] > 0) cleaned++;
    }

    cout << cleaned;
    
    return 0;
}
