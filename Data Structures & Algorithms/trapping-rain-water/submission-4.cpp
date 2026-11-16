class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());

        int pre_max = height[0];
        int pre_max_index = 0;

        prefix[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            if (height[i] > prefix[i-1]) {
                prefix[i] = height[i];
            }
            else prefix[i] = prefix[i-1];
            //std::cout << prefix[i] << endl;
        }

        suffix[height.size()-1] = height[height.size()-1];
        for (int i = height.size()-2; i >=0; i--) {
            if (height[i] > suffix[i+1]) {
                suffix[i] = height[i];
            }
            else suffix[i] = suffix[i+1];
            std::cout << suffix[i] << endl;
        }

        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            sum += std::min(prefix[i], suffix[i]) - height[i];
        }

        return sum;
    }
};
