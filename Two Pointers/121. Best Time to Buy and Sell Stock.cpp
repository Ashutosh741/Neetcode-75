class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size(),mini = INT_MAX;
        for(int i=0;i<n;i++){
            if(mini > prices[i]){
                mini = prices[i];
            }else{
                profit = max(profit,prices[i]-mini);
            }
        }
        return profit;

    }
};
