#include <iostream>
#include <vector>
#include <algorithm>

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool operator<(const Interval& lhs, const Interval& rhs)
{
    if (lhs.start == rhs.start)
    {
        return lhs.end < rhs.end;
    }
    return lhs.start < rhs.start;
}

class Solution
{
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals)
    {
        std::vector<Interval> res;
        std::sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 0)
        {
            return res;
        }

        res.push_back(intervals[0]);
        int index = 0;
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i].start >= res[index].start &&
                intervals[i].start <= res[index].end)
            {
                if (intervals[i].end > res[index].end)
                {
                    res[index].end = intervals[i].end;
                }
            }
            else
            {
                res.push_back(intervals[i]);
                ++index;
            }
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<Interval> v = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<Interval> res = sln.merge(v);
    for (auto item : res)
    {
        std::cout << "[" << item.start << ", " << item.end << "]" << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}

