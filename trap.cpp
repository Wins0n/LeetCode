#include <iostream>
#include <vector>

class Solution
{
public:
    int trap(int a[], int n)
    {
        if (n == 0)
        {
            return 0;
        }
        
        std::vector<int> l(n, 0), r(n, 0);
        int h;
        
        h = a[0];
        l[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            if (h > a[i])
            {
                l[i] = h - a[i];
            }
            h = std::max(h, a[i]);
        }
        h = a[n-1];
        r[n-1] = 0;
        for (int i = n-2; i >= 0; --i)
        {
            if (h > a[i])
            {
                r[i] = h - a[i];
            }
            h = std::max(h, a[i]);
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += std::min(l[i], r[i]);
        }
        return sum;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    std::cout << sln.trap(&a[0], a.size()) << std::endl;

    return 0;
}

