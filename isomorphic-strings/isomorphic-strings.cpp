class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }

        std::map<char, char> sTable;
        std::map<char, char> tTable;
        for(auto index = 0; index < s.size(); ++index)
        {
            auto sc = s[index];
            auto tc = t[index];

            auto it = sTable.find(sc);
            auto jt = tTable.find(tc);
            if(it == sTable.end())
            {
                sTable.insert({sc, tc});
            }
            else
            {
                if(it->second != tc)
                {
                    return false;
                }
            }

            if(jt == tTable.end())
            {
                tTable.insert({tc, sc});
            }
            else
            {
                if(jt->second != sc)
                {
                    return false;
                }
            }
        }

        return true;
    }
};