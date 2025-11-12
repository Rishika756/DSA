class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        curr_sum = 0
        maxi = -sys.maxsize 

        for i in range(n):
            curr_sum += nums[i]
            maxi = max(maxi, curr_sum)
            if curr_sum < 0:
                curr_sum = 0
        return maxi