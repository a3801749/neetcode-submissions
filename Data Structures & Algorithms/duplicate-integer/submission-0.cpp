class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int num : nums) {
            auto result = num_set.insert(num);
            if (result.second == false) {
                return true;
            }
        }
        return false;   
    }
};