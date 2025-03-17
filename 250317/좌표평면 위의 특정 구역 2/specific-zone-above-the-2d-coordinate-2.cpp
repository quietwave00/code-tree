#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dots[100][2];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> dots[i][0] >> dots[i][1];
    }

    // 하나씩 빼보기
    int min_area = 40000 * 40000;
    for(int remove = 0; remove < N; remove++) {
        int minX = 40001, minY = 40001;
        int maxX = 0, maxY = 0;
        for(int i = 0; i < N; i++) {
            if (i == remove) continue;

            minX = min(dots[i][0], minX);
            minY = min(dots[i][1], minY);
            maxX = max(dots[i][0], maxX);
            maxY = max(dots[i][1], maxY);

            // printf("%d %d %d %d\n", minX, minY, maxX, maxY);
        }
        int area = (maxX - minX) * (maxY - minY);
        min_area = min(min_area, area);
    }

    cout << min_area << endl;

    return 0;
}

// 점을 모두 포함하는 직사각형의 최소 넓이
// 하나씩 빼보기
// 점의 최대값, 최소값 구해서 넓이 구하기 
