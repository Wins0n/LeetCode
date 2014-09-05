#include <iostream>
#include <cstring>

// vector -> TLE
class Solution
{
private:
    int res;
    bool* flag;

private:
    void dfs(int row, int cur, int n)
    {
        if (cur == n)
        {
            ++res;
            return ;
        }
        for (int i = row; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!flag[i] && !flag[n+j] && !flag[2*n+i+j] && !flag[5*n-i+j-2])
                {
                    flag[i] = flag[n+j] = flag[2*n+i+j] = flag[5*n-i+j-2] = true;
                    dfs(i+1, cur+1, n);
                    flag[i] = flag[n+j] = flag[2*n+i+j] = flag[5*n-i+j-2] = false;
                }
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        res = 0;
        if (n)
        {
            flag = new bool[6*n-2];
            memset(flag, 0, sizeof(bool)*(6*n-2));
            dfs(0, 0, n);
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
        std::cout << sln.totalNQueens(n) << std::endl;
    }
    
    return 0;
}

