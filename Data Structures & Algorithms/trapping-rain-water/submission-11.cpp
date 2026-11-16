class Solution {
public:
    int trap(vector<int>& height) {

        if (height.size() == 0 || height.size() == 1) {
            return 0;
        }

        int l = 0;
        int r = height.size();
        int l_max = height[0];
        int r_max = height[height.size()-1];

        int sum = 0;

        while (l < r) {
            if (l_max < r_max) {
                l++;
                l_max = std::max(height[l], l_max);
                sum += l_max - height[l];
            }
            else {
                r--;
                r_max = std::max(height[r], r_max);
                sum += r_max - height[r];
            }
        }

        return sum;
    }
};
