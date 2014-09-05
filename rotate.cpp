#include <iostream>
#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int> >& m)
    {
        int n = m.size();
        int x = n/2;
        int y = (n&1) ? x+1 : x;
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                int tmp = m[i][j];
                m[i][j] = m[n-j-1][i];
                m[n-j-1][i] = m[n-i-1][n-j-1];
                m[n-i-1][n-j-1] = m[j][n-i-1];
                m[j][n-i-1] = tmp;
            }
        }
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

