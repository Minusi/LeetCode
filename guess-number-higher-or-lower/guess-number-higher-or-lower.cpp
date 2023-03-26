/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long lhsIndex = 0;
        long long rhsIndex = n;
        while(lhsIndex <= rhsIndex)
        {
            long long index = (lhsIndex + rhsIndex) / 2;
            if(guess(index) == -1)
            {
                rhsIndex = index - 1;
            }
            else if(guess(index) == 1)
            {
                lhsIndex = index + 1;
            }
            else
            {
                return index;
            }
        }

        return -1;
    }
};