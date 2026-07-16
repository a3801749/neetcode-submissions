class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            vector<int> result; result.push_back(i);
            int difference = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == difference) {
                    result.push_back(j);
                    return result;
                }
            }
        }    
    }
};
