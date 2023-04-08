class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> numSet;
        
        for(const auto num : nums)
        {
            auto it = numSet.insert(num);
            if(it.second == false)
            {
                return true;
            }
        }

        return false;
    }
};