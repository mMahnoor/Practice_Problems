#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> numsArr;
    vector<vector<int>> dp;
    int findTargetSumWays(vector<int> &nums, int target)
    {
        numsArr = nums;
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total)
            return 0;
        if ((target + total) % 2 != 0)
            return 0;
        int sum = (target + total) / 2;
        int n = nums.size();
        dp.assign(n + 1, vector<int>(sum + 1, -1));
        return countWays(n, sum);
    }
    int countWays(int n, int sum)
    {
        if (n == 0)
        {
            if (sum == 0)
                return 1;
            return 0;
        }
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (numsArr[n - 1] <= sum)
        {
            int op1 = countWays(n - 1, sum - numsArr[n - 1]);
            int op2 = countWays(n - 1, sum);
            dp[n][sum] = op1 + op2;
            return dp[n][sum];
        }
        else
            return dp[n][sum] = countWays(n - 1, sum);
    }
};