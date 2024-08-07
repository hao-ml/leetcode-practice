class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] - prices[i-1] > 0:
                profit += prices[i] - prices[i-1]

        return profit
    
sol = Solution()

# test cases
# prices = [7,1,5,3,6,4]
# prices = [1,2,3,4,5]
prices = [7,6,4,3,1]

print(sol.maxProfit(prices))