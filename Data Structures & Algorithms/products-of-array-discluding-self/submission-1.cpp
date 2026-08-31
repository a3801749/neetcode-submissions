class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = vector<int>(nums.size());
        vector<int> suffix = vector<int>(nums.size());
        vector<int> result = vector<int>(nums.size());

        prefix[0] = 0;
        suffix[nums.size() - 1] = nums[nums.size()-1];
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefix[i] = 1;
                suffix[nums.size() - 1] = 1;
            }
            else if (i == 1) {
                prefix[i] = nums[0];
                suffix[nums.size() - 2] = nums[nums.size() - 1];
            }
            else {
                prefix[i] = prefix[i-1] * nums[i-1];
                suffix[nums.size()-1-i] = suffix[nums.size()-i] * nums[nums.size()-i];
            }
            //cout << suffix[nums.size()-1-i] << endl;
        }

        prefix[0] = 1;
        suffix[nums.size() - 1] = 1;

        for (int i = 0; i < nums.size(); i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
