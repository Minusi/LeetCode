class Solution {
public:
	bool isInBoard(int n, std::pair<int, int> pos)
	{
		return (0 <= pos.first && pos.first < n) && (0 <= pos.second && pos.second < n);
	}

	double knightProbability(int n, int k, int row, int column) {
		vector<vector<vector<double>>> boards(k + 1);
		for (auto& board : boards)
		{
			board.resize(n);
			for (auto& row : board)
			{
				row.resize(n);
			}
		}

		pair<int, int> dir[8] =
		{
			{-2, 1}, {-1, 2}, {1, 2}, {2, 1},
			{2, -1}, {1, -2}, {-1, -2}, {-2, -1}
		};

		boards[0][row][column] = 1;
		for (int i = 1; i <= k; ++i)
		{
			for (int r = 0; r < n; ++r)
			{
				for (int c = 0; c < n; ++c)
				{
					for (int d = 0; d < 8; ++d)
					{
						pair<int, int> prevPos = { r + dir[d].first, c + dir[d].second };
						if (isInBoard(n, prevPos) == false)
						{
							continue;
						}

						boards[i][r][c] += boards[i - 1][prevPos.first][prevPos.second] / static_cast<double>(8);
					}
				}
			}
		}

		double prob = 0;
		for (int r = 0; r < n; ++r)
		{
			for (int c = 0; c < n; ++c)
			{
				prob += boards[k][r][c];
			}
		}

		return prob;
	}
};