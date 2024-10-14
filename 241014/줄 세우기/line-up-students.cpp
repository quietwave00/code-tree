#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;



int main() {
    int n;
    cin >> n;

    tuple<int, int, int> persons[n];
    for(int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        persons[i] = make_tuple(-h, w, i + 1);
        
    }

    sort(persons, persons + n);

    for(int i = 0; i < n; i++) {
        int h, w, num;
        tie(h, w, num) = persons[i];
        printf("%d %d %d\n", -h, w, num);
    }
     
    return 0;
}