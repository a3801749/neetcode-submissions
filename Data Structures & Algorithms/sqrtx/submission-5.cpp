class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        while (left < right) {
            int middle = (left + right)/2;
            if (x / middle < middle) {
                right = middle - 1;
            }
            else if (x / middle > middle) {
                left = middle + 1;
            }
            else return middle;
        }
        if (x / left < left)
            left --;
        return left;

    }
};