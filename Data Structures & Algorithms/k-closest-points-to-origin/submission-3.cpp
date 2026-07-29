class Solution {
public:

    struct greater_coordinate_compare {
        bool operator()(vector<int> point_a, vector<int> point_b) {
            return ((point_a[0] * point_a[0]) + (point_a[1] * point_a[1])) > ((point_b[0] * point_b[0]) + (point_b[1] * point_b[1]));
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      std::priority_queue<vector<int>, std::vector<vector<int>>, greater_coordinate_compare> min_pq(points.begin(), points.end());
      vector<vector<int>> result;
      
      for (int i = 0; i < k; i++) {
        result.push_back(min_pq.top());
        min_pq.pop();
      }
      
      return result;
      //return points;
    }
};
