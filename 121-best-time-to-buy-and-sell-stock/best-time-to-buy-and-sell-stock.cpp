class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1;
        int maxProfit = 0;
        while(sell < prices.size()){
            int profit = prices[sell] - prices[buy];
            maxProfit = max(maxProfit, profit);
            if(profit > 0){
                sell++;
            }
            else{
                buy = sell;
                sell++;
            }
        }
        return maxProfit;
    }
};