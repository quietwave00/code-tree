#include <iostream>

using namespace std;

int main() {

    string A;
    cin >> A;

    int cnt = 0;
    for(int i = 0; i < A.length(); i++) {
        // cout << "A[i]: " << A[i] << endl;
        if(A[i] == '(') {
            for(int j = i + 1; j < A.length(); j++) {
                // cout << "A[j]: " << A[j] << endl;
                if(A[j] == ')') cnt++;
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}

// memo
// (, )
// string A;
// for(i = 0; A.length; i++)
//  if(A[i] == '('))
// for(j = i + 1; A.length; j++)
//  if(A[j] == ')') cnt++; 