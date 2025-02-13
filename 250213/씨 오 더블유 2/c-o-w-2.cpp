#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main() {
    cin >> n;
    cin >> str;

    int cnt = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'C') {
            for(int j = i + 1; j < str.length(); j++) {
                if(str[j] == 'O') {
                    for(int k = j + 1; k < str.length(); k++) {
                        if(str[k] == 'W') cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}