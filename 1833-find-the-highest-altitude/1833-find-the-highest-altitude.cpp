class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxSum = 0;
        int sum = 0;
        for(auto delta : gain)
        {
            sum += delta;
            maxSum = std::max(maxSum, sum);
        }

        return maxSum;
    }
};