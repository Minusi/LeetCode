#include <algorithm>
#include <utility>

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::vector<int> lessNums = nums;
        std::sort(lessNums.begin(), lessNums.end(), std::less<int>());
        
        auto index = 0;
        while (lessNums[index] < target / (double)2)
        {
            ++index;
        }
        
        
        std::pair<int, int> values;
        for(int i = index; i < lessNums.size(); ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                if(lessNums[i] + lessNums[j] < target)
                {
                    break;
                }
                else if(lessNums[i] + lessNums[j] == target)
                {
                    values.first = std::min(lessNums[i], lessNums[j]);
                    values.second = std::max(lessNums[i], lessNums[j]);
                }
            }
        }
        

        std::pair<int, int> answer{ -1, -1 };
        for (auto index = 0; index < nums.size(); ++index)
        {
            if (nums[index] == values.first && answer.first == -1)
            {
                answer.first = index;
            }
            else if (nums[index] == values.second && answer.second == -1)
            {
                answer.second = index;
            }
        }

        return std::vector<int>({ answer.first, answer.second });
    }
};