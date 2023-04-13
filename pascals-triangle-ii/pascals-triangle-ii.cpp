class Solution {
public:
	vector<int> getRow(int rowIndex) {
		std::vector<int> result;
		result.resize(rowIndex + 1);
		result[0] = 1;

		auto endIt = result.begin() + 1;
		for (auto index = 1; index <= rowIndex; ++index)
		{
			std::vector<int> buffer{ result.begin(), endIt };
			buffer.push_back(0);
			for (auto lIndex = 0; lIndex < buffer.size(); ++lIndex)
			{
				if (lIndex == 0)
				{
					continue;
				}

				result[lIndex] = buffer[lIndex] + buffer[lIndex - 1];
			}
			++endIt;
		}

		return result;
	}
};