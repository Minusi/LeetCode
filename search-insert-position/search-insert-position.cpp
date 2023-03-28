class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lhsIndex = 0;
        int rhsIndex = nums.size() - 1;
        int midIndex = (lhsIndex + rhsIndex) / 2;
        while(lhsIndex < rhsIndex)
        {
            if(nums[midIndex] > target)
            {
                rhsIndex = midIndex - 1;               
            }
            else if(nums[midIndex] < target)
            {
                lhsIndex = midIndex + 1;
            }
            else
            {
                return midIndex;
            }

            midIndex = (lhsIndex + rhsIndex) / 2;
        }

        if(nums[midIndex] >= target)
        {
            return midIndex;
        }
        else
        {
            return midIndex + 1;
        }
    }
};