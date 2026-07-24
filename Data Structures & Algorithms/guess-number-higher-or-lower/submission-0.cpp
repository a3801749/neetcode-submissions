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
        int left = 0;
        int right = n;
        while (left < right) {
            cout << left << endl;
            cout << right << endl;
            int middle = (left + right)/2;
            int mid_result = guess(middle);
            cout << middle << endl;
            cout << guess(middle) << endl << endl;
            if (mid_result == -1) {
                right = middle - 1;
            }
            else if (mid_result == 1) {
                left = middle + 1;
            }
            else return middle;
        }
        return left;
    }
};