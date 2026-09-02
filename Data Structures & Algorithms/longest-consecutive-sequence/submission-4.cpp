class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());  
        int count = 1;
        int count_temp = 1;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i+1] == nums[i] + 1) {
                count_temp++;
                count = max(count, count_temp);
            }
            else if (nums[i+1] != nums[i]) {
                count_temp = 1;
            }
        }
        return count;
    }
};
