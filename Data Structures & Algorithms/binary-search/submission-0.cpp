class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int middle = nums[(left + right)/2];
            if (target < middle) {
                right = (left + right)/2 - 1;
            }
            else if (target > middle) {
                left = (left + right)/2 + 1;
            }
            else return (left + right)/2;
        }
        if (nums[left] == target) {
            return left;
        }
        else return -1;
    }
};
