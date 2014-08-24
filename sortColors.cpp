#include <iostream>
#include <vector>

class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int l = 0;
        int r = n-1;
        int i = 0;
        while (i <= r)
        {
            if (A[i] == 0 && i != l)
            {
                std::swap(A[l], A[i]);
                ++l;
            }
            else if (A[i] == 2)
            {
                std::swap(A[r], A[i]);
                --r;
            }
            else
            {
                ++i;
            }
        }
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int n;
    while (std::cin >> n)
    {
        std::vector<int> v(n, 0);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }
        sln.sortColors(&v[0], n);
        for (int i = 0; i < n; ++i)
        {
            std::cout << v[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}

