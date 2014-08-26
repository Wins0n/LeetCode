#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::vector<std::string> anagrams(std::vector<std::string>& s)
    {
        std::vector<std::string> res;
        std::unordered_map<std::string, int> um;
        
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            std::string str(s[i]);
            std::sort(str.begin(), str.end());
            std::unordered_map<std::string, int>::iterator iter;
            iter = um.find(str);
            if (iter == um.end())
            {
                um.insert(std::make_pair(str, i));
            }
            else
            {
                res.push_back(s[i]);
                if (iter->second >= 0)
                {
                    res.push_back(s[iter->second]);
                    iter->second = -1;
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

