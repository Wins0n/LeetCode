#include <iostream>
#include <vector>

class Solution
{
public:
    int maxArea(std::vector<int>& height)
    {
        int n = height.size();
        int i = 0, j = n-1;
        int maxArea = 0;

        while (i < j)
        {
            int area = std::min(height[i], height[j]) * (j-i);
            maxArea = std::max(maxArea, area);
            if (height[i] < height[j])
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        return maxArea;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int n;

    while (std::cin >> n)
    {
        std::vector<int> height(n, 0);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> height[i];
        }
        std::cout << sln.maxArea(height) << std::endl;
    }

    return 0;
}

