#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

class Student {
    public:
        int h, w, num;
    
    Student() {}
    Student(int h, int w, int num) {
        this->h = h;
        this->w = w;
        this->num = num;
    }
};

bool cmp(Student a, Student b) {
    if (a.h != b.h) return a.h > b.h;
    if (a.w != b.w) return a.w > b.w;
    return a.num < b.num;
}

int main() {
    int n;
    cin >> n;

    Student students[n];
    for(int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        students[i] = Student(h, w, i + 1);
    }

    sort(students, students + n, cmp);

    for(int i = 0; i < n; i++) {
        printf("%d %d %d\n", students[i].h, students[i].w, students[i].num);
    }
     
    return 0;
}