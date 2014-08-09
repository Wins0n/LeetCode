#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

class Solution
{
public:
    int ladderLength(std::string start, std::string end,
                     std::unordered_set<std::string>& dict)
    {
        if (start == end)
        {
            return 1;
        }
        
        std::unordered_map<std::string, int> depth;
        depth.insert(std::make_pair(start, 1));
        std::queue<std::string> q;
        q.push(start);

        while (!q.empty())
        {
            std::string word = q.front();
            q.pop();
            int len = word.length();
            int cur_depth = depth[word] + 1;
            for (int i = 0; i < len; ++i)
            {
                std::string s = word;
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    s[i] = ch;
                    if (dict.find(s) != dict.end() && depth.find(s) == depth.end())
                    {
                        depth.insert(std::make_pair(s, cur_depth));
                        q.push(s);
                    }
                    if (s == end)
                    {
                        return cur_depth;
                    }
                }
            }
        }
        return 0;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::unordered_set<std::string> dict = {"hot","dot","dog","lot","log"};
    std::string start("hit");
    std::string end("cog");
    std::cout << sln.ladderLength(start, end, dict) << std::endl;
    
    return 0;
}

