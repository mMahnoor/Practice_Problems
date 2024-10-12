#Problem Link: https://leetcode.com/problems/house-robber/

class Solution:
    def max_money(self,i, nums, dp) -> int:
        if (i == len(nums)-1):
            return nums[i]
        if (i > len(nums)-1):
            return 0
        if dp[i]!=-1:
            return dp[i]
        dp[i] = max(nums[i]+self.max_money(i+2,nums, dp),self.max_money(i+1,nums, dp))
        return dp[i]
    def rob(self, nums: list[int]) -> int:
        dp=[-1 for i in range(len(nums))]
        return self.max_money(0, nums, dp)
    
nums=list(map(int, input().split()))
Solution().rob(nums)