#include <iostream>
#include <vector>
#include <queue>

class Solution
{
private:
    struct Node
    {
        int x;
        int y;
        Node(int _x, int _y) : x(_x), y(_y) {}
    };
    
private:
    void BFS(std::vector<std::vector<char> >& m, 
             std::vector<std::vector<bool> >& v,
             int r, int c, int i, int j)
    {
        int steps[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        bool flag = (i == 0 || i == r-1 || j == 0 || j == c-1);
        std::queue<Node> q, track;
        track.push(Node(i, j));
        q.push(Node(i, j));
        v[i][j] = true;
        
        while (!q.empty())
        {
            Node node = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                Node tmp(node.x + steps[i][0], node.y + steps[i][1]);
                if (tmp.x >= 0 && tmp.x < r && tmp.y >= 0 && tmp.y < c &&
                    m[tmp.x][tmp.y] == 'O' && !v[tmp.x][tmp.y])
                {
                    q.push(tmp);
                    track.push(tmp);
                    v[tmp.x][tmp.y] = true;
                    if (tmp.x == 0 || tmp.x == r-1 || tmp.y == 0 || tmp.y == c-1)
                    {
                        flag = true;
                    }
                }
            }
        }
        if (flag == false)
        {
            while (!track.empty())
            {
                m[track.front().x][track.front().y] = 'X';
                track.pop();
            }
        }
    }
    
public:
    void solve(std::vector<std::vector<char> > &board)
    {
        int n = board.size();
        if (n == 0)
        {
            return ;
        }
        
        int m = board[0].size();
        std::vector<bool> vtmp(m, false);
        std::vector<std::vector<bool> > visited(n, vtmp);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    BFS(board, visited, n, m, i, j);
                }
            }
        }
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

