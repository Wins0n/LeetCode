#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix)
    {
        std::vector<int> v;
        int n = matrix.size();
        if (n == 0)
        {
            return v;
        }
        int m = matrix[0].size();
        if (m == 0)
        {
            return v;
        }

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        while (1)
        {
            for (int i = left; i <= right; ++i)
            {
                v.push_back(matrix[top][i]);
            }
            ++top;
            if (top > bottom)
            {
                break;
            }
            
            for (int i = top; i <= bottom; ++i)
            {
                v.push_back(matrix[i][right]);
            }
            --right;
            if (left > right)
            {
                break;
            }
            
            for (int i = right; i >= left; --i)
            {
                v.push_back(matrix[bottom][i]);
            }
            --bottom;
            if (top > bottom)
            {
                break;
            }
            
            for (int i = bottom; i >= top; --i)
            {
                v.push_back(matrix[i][left]);
            }
            ++left;
            if (left > right)
            {
                break;
            }
        }
        return v;
    }
};

int main(int argc, char** argv)
{
    std::vector<std::vector<int> > m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution sln;
    std::vector<int> v = sln.spiralOrder(m);
    for (auto item : v)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

