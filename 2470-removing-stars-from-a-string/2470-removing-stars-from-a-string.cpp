class Solution {
public:
    string removeStars(string s) {
        char result[100001] = { 0, };
        int insertPos = 0;

        for (int index = 0; index < s.size(); ++index)
        {
            if (s[index] == '*')
            {
                if (insertPos > 0)
                {
                    result[--insertPos] = '\0';
                }
            }
            else
            {
                result[insertPos++] = s[index];
            }
        }

        return result;

    }
};