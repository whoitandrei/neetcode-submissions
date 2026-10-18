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
        int curNum = n / 2;
        while (guess(curNum) != 0) {
            if (guess(curNum) == 1) {
                curNum = curNum + curNum / 2;
            } else {
                curNum = curNum - curNum / 2;
            }
        }

        return curNum;
    }
};