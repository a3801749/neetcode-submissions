class KthLargest {
public:


    priority_queue<int, vector<int>, std::greater<int>> min_pq;
    int k;

    KthLargest(int k, vector<int>& nums)
        : k(k)
        {
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if (min_pq.size() < k) {
            min_pq.push(val);
        }
        else if (min_pq.top() < val) {
            min_pq.pop();
            min_pq.push(val);
        }
        return min_pq.top();
    }
};
