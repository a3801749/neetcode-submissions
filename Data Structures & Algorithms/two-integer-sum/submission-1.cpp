class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_search;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto it = nums_search.find(target - nums[i]);
            if (it != nums_search.end()) {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }
            else {
                nums_search.insert({nums[i], i});
            }
        }
        return result;
    }
};
