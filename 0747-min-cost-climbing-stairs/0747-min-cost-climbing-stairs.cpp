class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (auto index = 2; index < cost.size(); ++index)
        {
            dp[index] = std::min(dp[index - 2], dp[index - 1]) + cost[index];
        }

        auto result = std::min(dp[cost.size() - 1], dp[cost.size() - 2]);
        return result;
    }
};