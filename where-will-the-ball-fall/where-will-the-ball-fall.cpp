class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int width = grid[0].size();
        std::vector<int> result;
        for (auto index = 0; index < grid[0].size(); ++index)
        {
            std::pair<int, int> ball = { 0, index };
            while (true)
            {
                if (grid[ball.first][ball.second] == 1)
                {
                    if (ball.second == width - 1)
                    {
                        ball.second = -1;
                        break;

                    }
                    else if (grid[ball.first][ball.second + 1] == -1)
                    {
                        ball.second = -1;
                        break;
                    }
                    else if (grid[ball.first][ball.second + 1] == 1)
                    {
                        ball.second += 1;
                    }
                }
                else if (grid[ball.first][ball.second] == -1)
                {
                    if (ball.second == 0)
                    {
                        ball.second = -1;
                        break;

                    }
                    else if (grid[ball.first][ball.second - 1] == 1)
                    {
                        ball.second = -1;
                        break;
                    }
                    else if (grid[ball.first][ball.second - 1] == -1)
                    {
                        ball.second -= 1;
                    }
                }

                ball.first += 1;
                if (ball.first >= grid.size())
                {
                    break;
                }
            }

            result.push_back(ball.second);
        }

        return result;
    }
};