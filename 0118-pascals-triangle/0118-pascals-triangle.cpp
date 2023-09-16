class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		std::vector<std::vector<int>> pascal(numRows);

		pascal[0].push_back(1);
		for (int i = 1; i < numRows; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0)
				{
					pascal[i].push_back(pascal[i - 1][j]);
				}
				else if (j == i)
				{
					pascal[i].push_back(pascal[i - 1][j - 1]);
				}
				else
				{
					pascal[i].push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
				}
			}
		}

		return pascal;
    }
};