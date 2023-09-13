class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t startIndex = 0;
        for (auto index = 0; index < nums.size(); ++index)
        {
            if (nums[index] != 0)
            {
                swap(nums[startIndex], nums[index]);
                ++startIndex;
            }
        }        
    }
};