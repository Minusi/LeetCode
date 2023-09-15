class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> result;

        for (auto asteroid : asteroids)
        {
            if (result.empty())
            {
                result.push_back(asteroid);
                continue;
            }

            bool newAsteroidAlive = true;
            while (result.empty() == false)
            {
                auto lastAsteroid = result.back();
                if ((lastAsteroid >= 0 && asteroid >= 0)
                    || (lastAsteroid < 0 && asteroid < 0)
                    || (lastAsteroid < 0 && asteroid > 0))
                {
                    break;
                }

                if (abs(lastAsteroid) > abs(asteroid))
                {
                    newAsteroidAlive = false;
                    break;
                }
                else if (abs(lastAsteroid) == abs(asteroid))
                {
                    newAsteroidAlive = false;
                    result.pop_back();
                    break;
                }
                else
                {
                    result.pop_back();
                }
            }

            if (newAsteroidAlive)
            {
                result.push_back(asteroid);
            }
        }

        return result;
    }
};