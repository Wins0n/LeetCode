#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int> > generateMatrix(int n)
    {
        std::vector<std::vector<int> > v(n, std::vector<int>(n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int val = 1;
        
        while (1)
        {
            for (int i = left; i <= right; ++i)
            {
                v[top][i] = val++;
            }
            ++top;
            if (top > bottom)
            {
                break;
            }
            
            for (int i = top; i <= bottom; ++i)
            {
                v[i][right] = val++;
            }
            --right;
            if (left > right)
            {
                break;
            }
            
            for (int i = right; i >= left; --i)
            {
                v[bottom][i] = val++;
            }
            --bottom;
            if (top > bottom)
            {
                break;
            }
            
            for (int i = bottom; i >= top; --i)
            {
                v[i][left] = val++;
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
    Solution sln;
    int n;
    while (std::cin >> n)
    {
        std::vector<std::vector<int> > v = sln.generateMatrix(n);
        for (auto vec : v)
        {
            for (auto item : vec)
            {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}

