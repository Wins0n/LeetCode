#include <iostream>

class Solution
{
public:
    int removeElement(int A[], int n, int elem)
    {
        int i = 0;
        int j = 0;
        while (i < n)
        {
            while (i < n && A[i] == elem)
            {
                ++i;
            }
            if (i == n)
            {
                break;
            }
            A[j++] = A[i++];
        }
        return j;
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

