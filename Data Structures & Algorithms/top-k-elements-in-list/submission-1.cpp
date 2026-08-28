class Solution {
public:

    struct ComparePairs {
        bool operator()(pair<int, int> p1, pair<int, int> p2) {
            return p1.second > p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map_help;
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, ComparePairs> pq;
        for (int i : nums) {
            map_help[i] += 1;
        }

        for (auto &val : map_help) {
            pq.push(val);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
