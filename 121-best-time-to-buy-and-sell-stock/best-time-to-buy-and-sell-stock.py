class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        if not nums:
            return 0
        currmax=nums[-1]
        sum=0
        for i in range(len(nums)-2,-1,-1):
            if currmax<nums[i]:
                currmax=nums[i]
            else:
                sum=max(sum,currmax-nums[i])
        return sum
        