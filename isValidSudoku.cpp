#include <iostream>
#include <vector>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char> >& board)
    {
        int n = 9;
        for (int i = 0; i < n; ++i)
        {
            std::vector<bool> row(n, false);
            std::vector<bool> col(n, false);
            for (int j = 0; j < n; ++j)
            {
                int rowIndex = board[i][j] - '1';
                int colIndex = board[j][i] - '1';
                if (board[i][j] != '.')
                {
                    if (row[rowIndex])
                    {
                        return false;
                    }
                    row[rowIndex] = true;
                }
                if (board[j][i] != '.')
                {
                    if (col[colIndex])
                    {
                        return false;
                    }
                    col[colIndex] = true;
                }
            }
        }
        
        int m = 3;
        for (int k = 0; k < n; ++k)
        {
            std::vector<bool> flag(n, false);
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    int rowIndex = k/3*3 + i;
                    int colIndex = k%3*3 + j;
                    int index = board[rowIndex][colIndex] - '1';
                    if (board[rowIndex][colIndex] != '.')
                    {
                        if (flag[index])
                        {
                            return false;
                        }
                        flag[index] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

