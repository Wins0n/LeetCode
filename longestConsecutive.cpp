#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    int longestConsecutive(std::vector<int>& num)
    {
        std::unordered_set<int> dict;
        for (auto item : num)
        {
            if (dict.find(item) == dict.end())
            {
                dict.insert(item);
            }
        }
        
        int res = 0;
        int tmp = 1;
        while (!dict.empty())
        {
            int elem = *(dict.begin());
            dict.erase(elem);
            int greater = elem+1;
            while (dict.find(greater) != dict.end())
            {
                tmp++;
                dict.erase(greater);
                greater++;
            }
            int less = elem-1;
            while (dict.find(less) != dict.end())
            {
                tmp++;
                dict.erase(less);
                less--;
            }
            res = std::max(res, tmp);
            tmp = 1;
        }

        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<int> num = {100, 4, 200, 1, 3, 2};

    std::cout << sln.longestConsecutive(num) << std::endl;

    return 0;
}

