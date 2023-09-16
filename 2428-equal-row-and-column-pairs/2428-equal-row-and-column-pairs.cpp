class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::map<string, int> rows{};
        std::map<string, int> cols{};
        std::vector<string> colcandidates(grid.size());

        for (auto i = 0; i < grid.size(); ++i)
        {
            const auto& col = grid[i];

            string rowString;
            for (auto j = 0; j < col.size(); ++j)
            {
                colcandidates[j].append(to_string(col[j]));
                colcandidates[j].append(",");
                rowString.append(to_string(col[j]));
                rowString.append(",");
            }

            if (rows.find(rowString) == rows.end())
            {
                rows.insert({ rowString, 1 });
            }
            else
            {
                rows[rowString] += 1;
            }
        }

        for (auto col : colcandidates)
        {
            if (cols.find(col) == cols.end())
            {
                cols.insert({ col, 1 });
            }
            else
            {
                cols[col] += 1;
            }
        }

        auto output = 0;
        for (auto row : rows)
        {
            auto it = cols.find(row.first);
            if (it == cols.end())
            {
                continue;
            }

            output += row.second * it->second;
        }

        return output;
    }
};