#include <iostream>
#include <string>
#include <vector>

class Solution
{
private:
    std::vector<std::string> res;

private:
    bool valid(const std::string& s, int beg, int end)
    {
        if (s[beg] == '0' && beg < end)
        {
            return false;
        }
        
        int val = 0;
        while (beg <= end)
        {
            val = val*10 + s[beg]-'0';
            ++beg;
        }
        return val >= 0 && val <= 255;
    }

    void dfs(const std::string& s, int part, int n, int beg, 
             std::vector<std::string>& ip)
    {
        if (part == 4)
        {
            if (beg == n)
            {
                std::string tmp(ip[0]);
                for (int i = 1; i < 4; ++i)
                {
                    tmp.push_back('.');
                    tmp.append(ip[i]);
                }
                res.push_back(tmp);
            }
            return ;
        }
        
        for (int i = 1; i <= 3; ++i)
        {
            if (beg+i-1 < n && valid(s, beg, beg+i-1))
            {
                ip.push_back(s.substr(beg, i));
                dfs(s, part+1, n, beg+i, ip);
                ip.pop_back();
            }
        }
    }
    
public:
    std::vector<std::string> restoreIpAddresses(std::string s)
    {
        std::vector<std::string> ip;
        res.clear();
        dfs(s, 0, s.length(), 0, ip);
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;
    
    while (std::cin >> s)
    {
        std::vector<std::string> vec = sln.restoreIpAddresses(s);
        for (auto item : vec)
        {
            std::cout << item << std::endl;
        }
    }
    
    return 0;
}

