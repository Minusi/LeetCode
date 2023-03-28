class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> concatenated;
        concatenated.resize(nums.size() * 2);
        
        auto preIndex = 0;
        auto postIndex = nums.size();
        for(const auto& num : nums)
        {
            concatenated[preIndex] = num;
            concatenated[postIndex] = num;

            ++preIndex;
            ++postIndex;
        }

        return concatenated;
    }
};