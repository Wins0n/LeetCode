#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> findSubstring(std::string S, std::vector<std::string>& L)
    {
        std::vector<int> res;
        std::unordered_map<std::string, int> count;
        int step = L.empty() ? 0 : L[0].length();
        int len = L.size() * step;
        for (auto item : L)
        {
            count[item]++;
        }
        
        int n = S.length();
        for (int i = 0; i < n-len+1; ++i)
        {
            std::unordered_map<std::string, int> tmp(count);
            int beg = i;
            while (true)
            {
                std::string s = S.substr(beg, step);
                auto iter = tmp.find(s);
                if (iter != tmp.end())
                {
                    iter->second--;
                    if (iter->second == 0)
                    {
                        tmp.erase(iter);
                    }
                }
                else
                {
                    break;
                }
                if (tmp.empty())
                {
                    res.push_back(i);
                    break;
                }
                beg += step;
            }
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string S("barfoothefoobarman");
    std::vector<std::string> L = {"foo", "bar"};
    
    std::vector<int> res = sln.findSubstring(S, L);
    for (auto item : res)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

