#include <iostream>
#include <vector>

class Solution
{
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        int total = 0;
        int sum = 0;
        int pre = -1;
        int n = gas.size();

        for (int i = 0; i < n; ++i)
        {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0)
            {
                pre = i;
                sum = 0;
            }
        }
        if (total >= 0)
        {
            return pre + 1;
        }
        return -1;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

