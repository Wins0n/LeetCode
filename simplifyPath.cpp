#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string simplifyPath(std::string path)
    {
        int dot = 0;
        std::vector<std::string> q;
        std::string tmp;
        
        std::string slash("/");
        path.append(slash);
        int n = path.length();
        
        for (int i = 0; i < n; ++i)
        {
            if (path[i] == '.')
            {
                ++dot;
            }
            else if (path[i] == '/')
            {
                if (tmp.empty())
                {
                    if (dot == 2 && !q.empty())
                    {
                        q.pop_back();
                    }
                    else if (dot > 2)
                    {
                        q.push_back(std::string(dot, '.'));
                        tmp = "";
                    }
                    dot = 0;
                }
                else
                {
                    q.push_back(tmp + std::string(dot, '.'));
                    tmp = "";
                    dot = 0;
                }
            }
            else
            {
                if (dot)
                {
                    tmp.append(std::string(dot, '.'));
                    dot = 0;
                }
                tmp.push_back(path[i]);
            }
        }
        
        tmp = "";
        for (std::vector<std::string>::iterator iter = q.begin();
             iter != q.end();
             ++iter)
        {
            tmp.append(slash + *iter);
        }
        if (tmp.empty())
        {
            tmp = slash;
        }
        return tmp;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;
    while (std::cin >> s)
    {
        std::cout << sln.simplifyPath(s) << std::endl;
    }
    
    return 0;
}

