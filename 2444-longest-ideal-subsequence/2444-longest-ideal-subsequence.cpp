class Solution {
public:
    int longestIdealString(string s, int k) {
		std::vector<std::vector<int>> dp(s.size());
		for (auto& row : dp)
		{
			row.resize(26);
		}

		dp[0][s[0] - 'a'] = 1;
		for (int i = 1; i < s.size(); ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				if (abs(s[i] - ('a' + j)) <= k)
				{
					dp[i][s[i] - 'a'] = std::max(dp[i][s[i] - 'a'], dp[i - 1][j] + 1);
				}

				dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
			}
		}

		auto result = std::max_element(dp[s.size() - 1].begin(), dp[s.size() - 1].end());
		return *result;        
    }
};