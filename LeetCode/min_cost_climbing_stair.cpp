// Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
#include <iostream>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {

        return min(totalCost(cost, 0, cost.size() - 1),
                   totalCost(cost, 1, cost.size() - 1));
    }
    int totalCost(vector<int> &cost, int i, int N)
    {
        if (i == N)
            return cost[i];
        else if (i > N)
            return 0;

        else
            return min(cost[i] + totalCost(cost, i + 2, N),
                       cost[i] + totalCost(cost, i + 1, N));
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