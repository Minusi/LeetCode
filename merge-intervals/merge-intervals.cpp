class Solution {
public:
    static bool lessRange(const std::vector<int>& lhs, const std::vector<int>& rhs)
    {
        if(lhs.empty()) return true;
        else if(rhs.empty()) return false;
        else return lhs[0] < rhs[0];
    }

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		std::vector<std::vector<int>> result;
		std::sort(intervals.begin(), intervals.end(), lessRange);

		int index = 0;
		while (index < intervals.size())
		{
			auto end = intervals[index][1];

			std::vector<int> elem;
			elem.push_back(intervals[index][0]);
			index++;
			while (index < intervals.size() && end >= intervals[index][0])
			{
				end = std::max(end, intervals[index][1]);
				index++;
			}

			elem.push_back(end);
			result.push_back(elem);
		}

		return result;
	}
};