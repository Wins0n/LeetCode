#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int> >& v)
{
    for (auto vec : v)
    {
        for (auto item : vec)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int> > &matrix)
    {
        int n = matrix.size();
        int m = n == 0 ? 0 : matrix[0].size();
        if (n == 0 || m == 0)
        {
            return ;
        }
        
        bool row = false;
        bool col = false;
        if (matrix[0][0] == 0)
        {
            row = col = true;
        }
        for (int i = 1; i < n; ++i)
        {
            if (matrix[i][0] == 0)
            {
                col = true;
                break;
            }
        }
        for (int i = 1; i < m; ++i)
        {
            if (matrix[0][i] == 0)
            {
                row = true;
                break;
            }
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < n; ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < m; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i)
        {
            if (matrix[0][i] == 0)
            {
                for (int j = 0; j < n; ++j)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        
        if (row)
        {
            for (int i = 0; i < m; ++i)
            {
                matrix[0][i] = 0;
            }
        }
        if (col)
        {
            for (int i = 0; i < n; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<std::vector<int> > v = {
        {0,0,0,5},
        {4,3,1,4},
        {0,1,1,4},
        {1,2,1,3},
        {0,0,1,1}
    };
    sln.setZeroes(v);
    printMatrix(v);
    
    return 0;
}

