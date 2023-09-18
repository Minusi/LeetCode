class Solution {
public:
    int maxVowels(string s, int k) {
        int result = 0;
        int count = 0;
        std::vector<bool> dp(k);
        for (auto i = 0; i < k; ++i)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                dp[i] = true;
                count++;
            }
            else
            {
                dp[i] = false;
            }
        }
        result = std::max(result, count);
        if (result == k)
        {
            return result;
        }
        
        size_t dpIndex = 0;
        for (auto i = k; i < s.length(); ++i, ++dpIndex)
        {
            if (dpIndex == k)
            {
                dpIndex = 0;
            }

            if (dp[dpIndex] == true)
            {
                count -= 1;
            }

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                dp[dpIndex] = true;
                count++;
            }
            else
            {
                dp[dpIndex] = false;
            }
            result = std::max(result, count);
            if (result == k)
            {
                return result;
            }
        }

        return result;
    }
};