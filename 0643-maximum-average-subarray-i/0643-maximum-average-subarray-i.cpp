class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k > nums.size())
        {
            return 0;
        }

        long long sum = 0;
        long double avr = 0;
        for (auto index = 0; index < nums.size(); ++index)
        {
            if (index < k)
            {
                sum += nums[index];
                if (index == k - 1)
                {
                    avr = sum / static_cast<long double>(k);
                }
            }
            else
            {
                sum = sum - nums[index - k] + nums[index];
                avr = std::max(avr, sum / static_cast<long double>(k));
            }
        }

        return avr;
    }
};