class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxSum = 0;
        int sum = 0;
        for(auto index = 0; index < gain.size(); ++index)
        {
            sum += gain[index];
            maxSum = std::max(maxSum, sum);
        }

        return maxSum;
    }
};