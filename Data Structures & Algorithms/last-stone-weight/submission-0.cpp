class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq;

        for (int i : stones) {
            pq.push(i);
        }

        while (pq.size() > 1) {
            int stone_1 = pq.top();
            pq.pop();

            int stone_2 = pq.top();
            pq.pop();

            if (stone_1 > stone_2) {
                stone_1 -= stone_2;
                pq.push(stone_1);
            }
            else if (stone_2 > stone_1) {
                stone_2 -= stone_1;
                pq.push(stone_2);
            }
        }
        if (pq.empty()) {
            return 0;
        }
        else return pq.top();
    }
};
