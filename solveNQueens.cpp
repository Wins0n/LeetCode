#include <iostream>
#include <cstring>
#include <vector>
#include <string>

class Solution
{
private:
    typedef std::vector<std::vector<std::string> > vvs_t;
    bool* flag;
    vvs_t res;
    
private:
    void dfs(int row, int cur, int n, std::vector<std::string>& map)
    {
        if (cur == n)
        {
            res.push_back(map);
            return ;
        }
        for (int i = row; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!flag[i] && !flag[n+j] && !flag[2*n+i+j] && !flag[5*n-i+j-2])
                {
                    flag[i] = flag[n+j] = flag[2*n+i+j] = flag[5*n-i+j-2] = true;
                    map[i][j] = 'Q';
                    dfs(i+1, cur+1, n, map);
                    flag[i] = flag[n+j] = flag[2*n+i+j] = flag[5*n-i+j-2] = false;
                    map[i][j] = '.';
                }
            }
        }
    }

public:
    vvs_t solveNQueens(int n)
    {
        res.clear();
        if (n)
        {
            std::vector<std::string> map(n, std::string(n, '.'));
            flag = new bool[6*n-2];
            memset(flag, 0, sizeof(bool)*(6*n-2));
            dfs(0, 0, n, map);
            delete []flag;
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int n;
    
    while (std::cin >> n)
    {
        std::vector<std::vector<std::string> > v = sln.solveNQueens(n);
        for (auto vec : v)
        {
            for (auto item : vec)
            {
                std::cout << item << std::endl;
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}

