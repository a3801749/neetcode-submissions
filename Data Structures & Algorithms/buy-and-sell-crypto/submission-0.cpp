class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int least = prices[0];
        int greatest = prices[0];
        int result = 0;
        while (i < prices.size()) {
            while (i+1 < prices.size() && prices[i+1] < prices[i]) {
                i++;
            }
            least = prices[i];
            while (i+1 < prices.size() && prices[i+1] > least) {
                i++;
                greatest = prices[i];
                if (greatest - least > result) {
                    result = greatest - least;
                }
            }

            i++;
        }  
        return result;
    }
};
