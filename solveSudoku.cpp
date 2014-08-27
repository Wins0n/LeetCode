#include <iostream>
#include <vector>

class Solution
{
private:
    struct Point
    {
        int x;
        int y;
        Point(int row=0, int col=0) : x(row), y(col) {}
    };
    
private:
    bool ok;
    int total;
    std::vector<Point> points;
    
private:
    bool valid(std::vector<std::vector<char> >& board, int x, int y, char val)
    {
        for (int i = 0; i < 9; ++i)
        {
            if ((i != y && board[x][i] == val) ||
                (i != x && board[i][y] == val))
            {
                return false;
            }
        }
        for (int i = x/3*3; i < x/3*3+3; ++i)
        {
            for (int j = y/3*3; j < y/3*3+3; ++j)
            {
                if (i != x && j != y && board[i][j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void init(std::vector<std::vector<char> >& board)
    {
        ok = false;
        points.clear();
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    points.push_back(Point(i, j));
                }
            }
        }
        total = points.size();
    }

    void dfs(std::vector<std::vector<char> >& board, int count)
    {
        if (count == total)
        {
            ok = true;
        }
        if (ok)
        {
            return ;
        }

        int x = points[count].x;
        int y = points[count].y;
        for (char val = '1'; val <= '9'; ++val)
        {
            if (valid(board, x, y, val))
            {
                board[x][y] = val;
                dfs(board, count+1);
                if (ok)
                {
                    return ;
                }
                board[x][y] = '.';
            }
        }
    }
    
public:
    void solveSudoku(std::vector<std::vector<char> >& board)
    {
        init(board);
        dfs(board, 0);
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

