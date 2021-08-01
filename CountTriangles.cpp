#include <bits/stdc++.h>
using namespace std;
class Point
{
public:
    int x;
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
int main()
{
    vector<Point> points{Point(1, 2), Point(2, 0), Point(2, 2), Point(2, 3), Point(4, 2)};
    unordered_map<int, int> xFreqMap;
    unordered_map<int, int> yFreqMap;
    for (auto p : points)
    {
        xFreqMap[p.x]++;
        yFreqMap[p.y]++;
    }
    int count = 0;
    for (Point p : points)
    {
        int n = xFreqMap[p.x];
        int m = yFreqMap[p.y];
        count += (n - 1) * (m - 1);
    }
    cout << count << endl;
    return 0;
}