class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        maxprofit = 0
        for i in range(len(prices)):
            if prices[i] < buy:
                buy = prices[i]
            else:
                currentprofit = prices[i] - buy
                maxprofit = max(maxprofit , currentprofit)
        return maxprofit
