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

class Solution
{
public:
    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval)
    {
        std::vector<Interval> res;
        int n = intervals.size();
        bool merged = false;
        bool added = false;
        
        int i = 0;
        for (; i < n; ++i)
        {
            if (newInterval.end < intervals[i].start || 
                intervals[i].end < newInterval.start)
            {
                if (merged || newInterval.end < intervals[i].start)
                {
                    added = true;
                    res.push_back(newInterval);
                    break;
                }
                else
                {
                    res.push_back(intervals[i]);
                }
            }
            else
            {
                newInterval.start = std::min(newInterval.start, intervals[i].start);
                newInterval.end = std::max(newInterval.end, intervals[i].end);
                merged = true;
            }
        }
        for (; i < n; ++i)
        {
            res.push_back(intervals[i]);
        }
        if (added == false)
        {
            res.push_back(newInterval);
        }
        
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<Interval> v = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<Interval> res = sln.insert(v, Interval(4,9));
    for (auto item : res)
    {
        std::cout << "[" << item.start << ", " << item.end << "]" << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}

