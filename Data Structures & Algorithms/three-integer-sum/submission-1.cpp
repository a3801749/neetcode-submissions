class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());

        for (int left = 0; left <= nums.size() - 2; left++) {
            if (nums[left] > 0) { break; }
            if (left > 0 && nums[left] == nums[left - 1]) { continue; }
            int lo = left + 1;
            int hi = nums.size() - 1;
            while (lo < hi) {
                int sum = nums[left] + nums[lo] + nums[hi];
                if (sum > 0) {
                    hi--;
                }
                else if (sum < 0) {
                    lo++;
                }
                else {
                    vector<int> v{nums[left], nums[lo], nums[hi]};
                    result.push_back(v);
                    while (lo < hi && nums[lo] == nums[lo + 1]) {
                        lo++;
                    }
                    while (lo < hi && nums[hi] == nums[hi - 1]) {
                        hi--;
                    }
                    lo++; hi--;
                }
            }
        }

        return result;
    }
};
