#include <iostream>
#include <algorithm>

using namespace std;

class Student {
    public:
        string name;
        int score1, score2, score3;

    Student() {}
    Student(string name, int score1, int score2, int score3) {
        this->name = name;
        this->score1 = score1;
        this->score2 = score2;
        this->score3 = score3;
    }
};

bool compare(Student a, Student b) {
    return a.score1 + a.score2 + a.score3 < b.score1 + b.score2 + b.score3;
}

int main() {
    int n;
    cin >> n;

    Student students[n];
    for(int i = 0; i < n; i++) {
        string name;
        int score1, score2, score3;
        cin >> name >> score1 >> score2 >> score3;
        students[i] = Student(name, score1, score2, score3);
    }

    sort(students, students + n, compare);

    for(int i = 0; i < n; i++) {
        printf("%s %d %d %d\n", students[i].name.c_str(), students[i].score1, students[i].score2, students[i].score3);
    }
    
    return 0;
}