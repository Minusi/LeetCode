class Solution {
public:
    vector<int> countBits(int n) {
         std::vector<int> result;
        result.reserve(n);
        result.push_back(0);
        if (n == 0) 
        {
            return result;
        }
        result.push_back(1);
        if (n == 1)
        {
            return result;
        }

        auto num = 2;
        while (num <= n)
        {
            auto size = result.size();
            for (auto index = 0; index < size && size + index <= n; ++index)
            {
                result.push_back(1 + result[index]);
            }

            num *= 2;
        }

        return result;
    }
};