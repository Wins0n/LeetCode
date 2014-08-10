#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minimumTotal(std::vector<std::vector<int> >& triangle)
    {
        int n = triangle.size();
        std::vector<std::vector<int> > v(2, std::vector<int>(n, 0));
        v[0][0] = triangle[0][0];
        int res = 0x7FFFFFFF;
        
        for (int i = 1; i < n; ++i)
        {
            int cur = (i&1);
            int pre = (cur+1) % 2;
            v[cur][0] = triangle[i][0] + v[pre][0];
            for (int j = 1; j < i; ++j)
            {
                v[cur][j] = std::min(v[pre][j-1], v[pre][j]) + triangle[i][j];
            }
            v[cur][i] = v[pre][i-1] + triangle[i][i];
        }
        for (int i = 0; i < n; ++i)
        {
            res = std::min(res, v[(n-1)&1][i]);
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<std::vector<int>> v = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    std::cout << sln.minimumTotal(v) << std::endl;
    
    return 0;
}

