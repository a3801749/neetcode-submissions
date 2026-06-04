class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(0,0, nums);
    }
    int dfs(int index, int currentXor, vector<int>& nums) {
        if (index == nums.size()) { return currentXor; }
        return dfs(index + 1, currentXor ^ nums[index], nums) + 
               dfs(index + 1, currentXor, nums);
    }
};