#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    std::vector<std::vector<bool> > visited;
    int row;
    int col;
    std::string word;
    int len;
    bool find;
    std::vector<std::vector<int> > steps;

private:
    void dfs(std::vector<std::vector<char> >& board, int x, int y, int index)
    {
        if (index == len)
        {
            find = true;
        }
        if (find)
        {
            return ;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int xx = x + steps[i][0];
            int yy = y + steps[i][1];
            if (xx >= 0 && xx < row && yy >= 0 && yy < col && 
                !visited[xx][yy] && board[xx][yy] == word[index])
            {
                visited[xx][yy] = true;
                dfs(board, xx, yy, index+1);
                visited[xx][yy] = false;
                if (find)
                {
                    return ;
                }
            }
        }
    }
    
public:
    bool exist(std::vector<std::vector<char> >& board, std::string word)
    {
        row = board.size();
        if (row == 0)
        {
            return false;
        }
        col = board[0].size();
        this->word = word;
        len = word.length();
        find = false;
        steps = std::vector<std::vector<int> >({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        visited = std::vector<std::vector<bool> >(row, std::vector<bool>(col, false));
        
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    dfs(board, i, j, 1);
                    if (find)
                    {
                        break;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return find;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<std::vector<char> > board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    std::string word;

    while (std::cin >> word)
    {
        std::cout << std::boolalpha << sln.exist(board, word) << std::endl;
    }

    return 0;
}

