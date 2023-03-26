class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lhsIndex = 0;
        int rhsIndex = nums.size() - 1;
        int index = 0;
        while (lhsIndex < nums.size() && rhsIndex >= 0)
        {
            if (lhsIndex == rhsIndex)
            {
                if (nums[lhsIndex] == target)
                {
                    return lhsIndex;
                }
                else
                {
                    return -1;
                }
            }

            int index = (lhsIndex + rhsIndex) / 2;
            if (nums[index] == target)
            {
                return index;
            }
            else if (nums[index] > target)
            {
                rhsIndex = index - 1;
            }
            else
            {
                lhsIndex = index + 1;
            }
        }

        return -1;
    }
};