class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit {0};
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            int sellValue = prices[i];
            vector<int> buyValues (prices.begin(), prices.begin() + i);
            sort(buyValues.begin(), buyValues.end());
            
            if(buyValues.size() > 0)
            {
                int highestProfit = sellValue - buyValues[0];
                if(highestProfit > profit)
                {
                    profit = highestProfit;
                }
            }
        }
        return profit;
    }
};
