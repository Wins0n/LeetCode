#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool operator<(const Point& lhs, const Point& rhs)
{
    return lhs.x < rhs.x;
}

class Solution
{
public:
    int maxPoints(std::vector<Point>& points)
    {
        int n = points.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        
        std::sort(points.begin(), points.end());
        int res = 0;
        double INF = std::numeric_limits<double>::infinity();
        
        for (int i = 0; i < n; ++i)
        {
            int same = 1;
            std::unordered_map<double, int> count;
            for (int j = i+1; j < n; ++j)
            {
                double k;
                bool same_point = false;
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    same_point = true;
                    ++same;
                }
                else if (points[i].x == points[j].x && points[i].y != points[j].y)
                {
                    k = INF;
                }
                else
                {
                    k = (points[j].y - points[i].y)*1.0 / (points[j].x - points[i].x);
                }
                if (!same_point)
                {
                    count[k]++;
                }
                if (count[k] + same > res)
                {
                    res = count[k] + same;
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    return 0;
}

