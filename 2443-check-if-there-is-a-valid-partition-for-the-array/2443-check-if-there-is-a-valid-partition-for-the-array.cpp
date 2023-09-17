class Solution {
public:
	bool isValidPartition(int a, int b) const
	{
		return a == b;
	}
	bool isValidPartition(int a, int b, int c) const
	{
		if (a == b && b == c && c == a)
		{
			return true;
		}
		else if (b == a + 1 && c == b + 1)
		{
			return true;
		}

		return false;
	}

	bool validPartition(const vector<int>& nums) {
		std::vector<bool> dp(nums.size());
		dp[0] = false;
		dp[1] = isValidPartition(nums[0], nums[1]);
		if (nums.size() == 2)
		{
			return dp[1];
		}
		dp[2] = isValidPartition(nums[0], nums[1], nums[2]);
		if (nums.size() == 3)
		{
			return dp[2];
		}

		for (int i = 3; i < nums.size(); ++i)
		{
			if (dp[i - 2] == true && isValidPartition(nums[i - 1], nums[i]))
			{
				dp[i] = true;
			}
			else if (dp[i - 3] == true)
			{
				if (isValidPartition(nums[i - 2], nums[i - 1], nums[i]))
				{
					dp[i] = true;
				}
			}
			else
			{
				dp[i] = false;
			}
		}

		return dp[nums.size() - 1];
	}
};