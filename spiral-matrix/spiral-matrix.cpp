class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;

        // e, s, w, n
        std::pair<int, int> directions[4] =
        {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };
        int direction = 1;
        std::pair<int, int> index = {0, matrix[0].size() - 1};


        result.insert(result.end(), matrix[0].begin(), matrix[0].end());
        int rowCount = matrix.size() - 1;
        int colCount = matrix[0].size() - 1;
        while(rowCount >= 0 && colCount >= 0)
        {
            if(direction % 2 == 0)
            {
                for(auto i = 0; i < colCount; ++i)
                {
                    index.first += directions[direction].first;
                    index.second += directions[direction].second;
                    result.push_back(matrix[index.first][index.second]);
                }
                --colCount;
            }
            else
            {
                for(auto i = 0; i < rowCount; ++i)
                {
                    index.first += directions[direction].first;
                    index.second += directions[direction].second;
                    result.push_back(matrix[index.first][index.second]);
                }
                --rowCount;
            }

            direction = (direction + 1) % 4;
        }

        return result;
    }
};