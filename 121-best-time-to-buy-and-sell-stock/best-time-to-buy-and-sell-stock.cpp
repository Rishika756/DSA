class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxiprofit = 0;
        int buy = prices[0];
        for(int i = 0; i<prices.size() ; i++){
            if(buy > prices[i]){
                buy = prices[i];
            }else{
                int currprofit = prices[i] - buy;
                maxiprofit = max(maxiprofit , currprofit);
            }
        }
        return maxiprofit;
    }
};