class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
        {
            return 0;
        }

        int maxProfit = 0;
        int start = prices[0];
        int end = prices[0];
        bool isRising = true;
        for(auto index = 1; index < prices.size(); ++index)
        {
            if(isRising)
            {
                if(prices[index] > end)
                {
                    end = prices[index];
                }
                else if(prices[index] < start)
                {
                    maxProfit = std::max(maxProfit, end - start);
                    start = end;
                    end = prices[index];
                    isRising = false;
                }
            }
            else
            {
                if(prices[index] < end)
                {
                    end = prices[index];
                }
                else if(prices[index] > end)
                {
                    start = end;
                    end = prices[index];
                    isRising = true;
                }
            }
        }

        maxProfit = std::max(maxProfit, end - start);
        return maxProfit;
    }
};