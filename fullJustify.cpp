#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int L)
    {
        int n = words.size();
        int i = 0;
        std::vector<std::string> res;

        while (i < n)
        {
            int count = 1;
            int len = words[i].size();
            int words_len = len;
            ++i;
            while (i < n)
            {
                int m = words[i].size();
                if (len + m + 1 <= L)
                {
                    len += m + 1;
                    words_len += m;
                }
                else
                {
                    break;
                }
                ++count;
                ++i;
            }
            int spaces = L - words_len;
            if (count == 1)
            {
                res.push_back(words[i-1] + std::string(spaces, ' '));
                continue;
            }
            int per = spaces / (count-1);
            int left = spaces % (count-1);
            int j = i - count;
            std::string tmp;

            if (i == n)
            {
                tmp = words[j];
                ++j;
                while (j < i)
                {
                    tmp += " " + words[j];
                    ++j;
                }
                tmp += std::string(L - tmp.size(), ' ');
            }
            else
            {
                tmp = words[j];
                j++;
                while (j < i)
                {
                    tmp += std::string(left > 0 ? per+1 : per, ' ') + words[j];
                    --left;
                    ++j;
                }
            }
            res.push_back(tmp);
        }

        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<std::string> words = {""};
    int L = 0;

    std::vector<std::string> vec = sln.fullJustify(words, L);
    for (auto s : vec)
    {
        std::cout << s << std::endl;
    }

    return 0;
}

