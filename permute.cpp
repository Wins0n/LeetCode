#include <iostream>
#include <vector>

class Solution
{
private:
    std::vector<std::vector<int> > res;
    std::vector<bool> visited;

private:
    void dfs(const std::vector<int>& a, int n, std::vector<int>& tmp)
    {
        if (tmp.size() == n)
        {
            res.push_back(tmp);
            return ;
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                tmp.push_back(a[i]);
                visited[i] = true;
                dfs(a, n, tmp);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    std::vector<std::vector<int> > permute(std::vector<int>& num)
    {
        int n = num.size();
        res.clear();
        visited = std::vector<bool>(n, false);
        
        std::vector<int> tmp;
        dfs(num, n, tmp);
        
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<int> num = {1, 2, 3};
    std::vector<std::vector<int> > v = sln.permute(num);

    for (auto vec : v)
    {
        for (auto item : vec)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

