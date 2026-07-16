class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> init;

        result.push_back(init);
        add_subset(0, result, init, nums);
        return result;
    }

    void add_subset(int index, vector<vector<int>>& result, vector<int> current, vector<int> & nums) {
        auto subset_with_index = current;
        subset_with_index.push_back(nums[index]);
        result.push_back(subset_with_index);
        if (index + 1 < nums.size()) {
            add_subset(index + 1, result, subset_with_index, nums);
            add_subset(index + 1, result, current, nums);
        }
    }
};
