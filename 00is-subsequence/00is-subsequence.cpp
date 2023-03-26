class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size())
        {
            return false;
        }

        auto sIndex = 0;
        for(auto tIndex = 0; tIndex < t.length(); ++tIndex)
        {
            if(sIndex >= s.size())
            {
                return true;
            }

            if(s[sIndex] == t[tIndex])
            {
                ++sIndex;
            }
        }

        return sIndex == s.size();
    }
};