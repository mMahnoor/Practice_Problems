#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;
        dp.assign(n, vector<int>(target + 1, -1));
        if (sum % 2 == 0)
        {
            return calcSum(n - 1, nums, target);
        }
        else
        {
            return false;
        }
    }
    bool calcSum(int i, vector<int> &nums, int target)
    {
        if (i == 0)
        {
            if (target == 0)
                return true;
            else
                return false;
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        if (nums[i - 1] <= target)
        {
            bool op1 = calcSum(i - 1, nums, target - nums[i - 1]);
            bool op2 = calcSum(i - 1, nums, target);
            return dp[i][target] = op1 || op2;
        }
        else
        {
            return dp[i][target] = calcSum(i - 1, nums, target);
        }
    }
};