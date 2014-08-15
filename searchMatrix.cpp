#include <iostream>
#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int> >& matrix, int target)
    {
        int row = matrix.size();
        if (row == 0)
        {
            return false;
        }
        int col = matrix[0].size();
        if (col == 0)
        {
            return false;
        }
        
        int top = 0;
        int bottom = row - 1;
        int middle = 0;
        while (top <= bottom)
        {
            middle = top + (bottom - top)/2;
            if (target > matrix[middle][col-1])
            {
                top = middle + 1;
            }
            else if (target < matrix[middle][0])
            {
                bottom = middle - 1;
            }
            else
            {
                break;
            }
        }

        int l = 0;
        int r = col - 1;
        while (l <= r)
        {
            int m = l + (r - l)/2;
            if (target > matrix[middle][m])
            {
                l = m + 1;
            }
            else if (target < matrix[middle][m])
            {
                r = m - 1;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};

int main(int argc, char **argv)
{
    std::vector<std::vector<int> > v = 
    {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    Solution sln;
    std::cout << std::boolalpha << sln.searchMatrix(v, 3) << std::endl;
    std::cout << std::boolalpha << sln.searchMatrix(v, 100) << std::endl;
    
    return 0;
}
