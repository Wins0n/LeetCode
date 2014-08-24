#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        std::vector<int> res;
        std::unordered_multimap<int, int> um;
        int n = numbers.size();
        
        for (int i = 0; i < n; ++i)
        {
            um.insert(std::make_pair(numbers[i], i));
        }
        for (int i = 0; i < n; ++i)
        {
            auto r = um.equal_range(target - numbers[i]);
            if (r.first != um.end())
            {
                if (numbers[i] != target - numbers[i])
                {
                    auto r2 = um.equal_range(numbers[i]);
                    res.push_back(std::min(r.first->second, r2.first->second) + 1);
                    res.push_back(std::max(r.first->second, r2.first->second) + 1);
                    break;
                }
                else
                {
                    auto iter = r.first;
                    ++iter;
                    if (iter != r.second)
                    {
                        auto r2 = um.equal_range(numbers[i]);
                        res.push_back(std::min(iter->second, r2.first->second) + 1);
                        res.push_back(std::max(iter->second, r2.first->second) + 1);
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<int> v = {2, 7, 11, 15};
    v = sln.twoSum(v, 9);
    
    if (!v.empty())
    {
        std::cout << v[0] << ", " << v[1] << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
    
    return 0;
}

