class Solution {
public:
    void sortColors(vector<int>& nums) {
        bool isSorted = false;
        while(isSorted == false)
        {
            isSorted = true;
            for(auto index = 0; index < nums.size() - 1; ++index)
            {
                if(nums[index] > nums[index + 1])
                {
                    int temp = nums[index];
                    nums[index] = nums[index + 1];
                    nums[index + 1] = temp;
                    isSorted = false;
                }
            }
        }
    }
};