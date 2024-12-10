#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    int num = 0;
    for(int i = 0; i < str.length(); i++) {
        for(int j = i + 1; j < str.length(); j++) {
            if(str[i] != '(') {
                break;
            } else {
                if(str[j] == ')') num++;
            }
        }
    }

    cout << num;
    
    return 0;
}