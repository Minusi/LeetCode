class Solution {
public:
    string removeStars(string s) {
        list<char> result;
        for (const auto& character : s)
        {
            if (character == '*')
            {
                if (result.empty() == false)
                {
                    result.pop_back();
                }
            }
            else
            {
                result.push_back(character);
            }
        }

        std::stringstream ss;
        for (const auto& character : result)
        {
            ss << character;
        }

        return ss.str();        
    }
};