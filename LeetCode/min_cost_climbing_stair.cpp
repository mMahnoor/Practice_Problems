// Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        dp.assign(n, -1);

        return min(totalCost(0, cost), totalCost(1, cost));
    }
    int totalCost(int i, vector<int> &cost)
    {
        if (i == cost.size() - 1)
            return cost[i];
        else if (i > cost.size() - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        dp[i] = min(cost[i] + totalCost(i + 2, cost),
                    cost[i] + totalCost(i + 1, cost));
        return dp[i];
    }
};

int main()
{
    Solution s = Solution();
    int arr[] = {10, 15, 20};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    cout << s.minCostClimbingStairs(v) << endl;
    return 0;
}