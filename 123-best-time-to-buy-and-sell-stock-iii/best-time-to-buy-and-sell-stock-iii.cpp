class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int dp[2][5];
        for(int day = (int) prices.size();day >= 0;day--){
            for(int transactionsLeft = 0;transactionsLeft <= 4;transactionsLeft++){
                int &ans = dp[day % 2][transactionsLeft];
                
                if(day == prices.size()){
                    ans = 0;
                }else if(transactionsLeft == 0){
                    ans = 0;
                }else{
                    int ans1 = dp[(day + 1) % 2][transactionsLeft];    
                    int ans2 = 0;
                    bool buy = (transactionsLeft % 2 == 0);

                    if(buy == true){
                        ans2 = -prices[day] + dp[(day + 1) % 2][transactionsLeft - 1];
                    }else{ 
                        ans2 = prices[day] + dp[(day + 1) % 2][transactionsLeft - 1];
                    }
                    ans = max(ans1, ans2);
                }
            }
        }
        return dp[0][4];
    }
};