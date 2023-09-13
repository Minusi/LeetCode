class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k > nums.size())
        {
            return 0;
        }

        long long sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        long double avr = sum / static_cast<long double>(k);
        for (auto index = 0; index + k < nums.size(); ++index)
        {
            sum = sum - nums[index] + nums[index + k];
            avr = std::max(avr, sum / static_cast<long double>(k));
        }

        return avr;
    }
};