class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int maxNum = INT_MIN;
        int rising = true;

        int accSum = 0;
        int maxProfit = INT_MIN;
        for (auto index = 0; index < nums.size(); ++index)
        {
            accSum += nums[index];
            maxNum = std::max(maxNum, nums[index]);
            if (rising)
            {
                if (accSum > end)
                {
                    end = accSum;
                }
                else if (accSum < start)
                {
                    if (start < end)
                    {
                        maxProfit = std::max(maxProfit, end - start);
                    }
                    start = end;
                    end = accSum;
                    rising = false;
                }
            }
            else
            {
                if (accSum < end)
                {
                    end = accSum;
                }
                else if (accSum > end)
                {
                    start = end;
                    end = accSum;
                    rising = true;
                }
            }
        }

        if (end > start)
        {
            maxProfit = std::max(maxProfit, end - start);
        }
        else
        {
            maxProfit = std::max(maxProfit, maxNum);
        }
        return maxProfit;
    }
};