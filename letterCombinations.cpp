#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    std::vector<std::string> map;
    std::vector<std::string> res;

private:
    void dfs(const std::string& s, int n, int beg, std::string& str)
    {
        if (beg == n)
        {
            res.push_back(str);
            return ;
        }
        char ch = s[beg];
        for (int i = 0; i < map[ch-'0'].length(); ++i)
        {
            str.push_back(map[ch-'0'][i]);
            dfs(s, n, beg+1, str);
            str.pop_back();
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string& digits)
    {
        res.clear();
        map = std::vector<std::string>{
            "", "", "abc", "def", "ghi", "jkl", 
            "mno", "pqrs", "tuv", "wxyz"
        };
        std::string s;
        dfs(digits, digits.length(), 0, s);
        return res;
    }
};

int main(int argc, char** argv)
{
    std::string digits;
    Solution sln;
    
    while (std::cin >> digits)
    {
        std::vector<std::string> vec = sln.letterCombinations(digits);
        for (auto item : vec)
        {
            std::cout << item << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}

