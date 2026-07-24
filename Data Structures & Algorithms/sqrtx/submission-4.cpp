class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) { return 1; }
        int left = 1;
        int right = x;
        while (left < right) {
            cout << left << endl;
            cout << right << endl;
            int middle = (left + right)/2;
            cout << middle << endl;
            cout << x / middle << endl << endl;
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
        // if (left * left > x) {
        //     return left - 1;
        // }
        // else return left;
    }
};