class Solution {
public:
    int longestPalindrome(string s) {
        int waiting[128] = {0,};

        int result = 0;
        for(const auto& ch : s)
        {
            if(waiting[ch] == 1)
            {
                waiting[ch] = 0;
                result += 2;
            }
            else
            {
                waiting[ch] += 1;
            }
        }

        for(auto index = static_cast<int>('A'); index <= static_cast<int>('z'); ++index)
        {
            if(waiting[index] > 0)
            {
                result += 1;
                break;
            }
        }

        return result;
    }
};