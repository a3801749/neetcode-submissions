class Solution {
public:

    struct greater_coordinate_compare {
        bool operator()(vector<int> point_a, vector<int> point_b) {
            return ((point_a[0] * point_a[0]) + (point_a[1] * point_a[1])) > ((point_b[0] * point_b[0]) + (point_b[1] * point_b[1]));
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      int left = 0;
      int right = points.size() -1;
      int pivot = points.size();

      while (pivot != k) {
        pivot = partition(points, left, right);
        if (pivot < k) {
            left = pivot + 1;
        }
        else {
            right = pivot - 1;
        }
      }
      return vector<std::vector<int>>(points.begin(), points.begin() + k);
    }

    int partition(vector<vector<int>>& points, int l, int r) {
        int pivot = r;
        int pivot_distance = distance_calc(points[pivot]);
        int i = l;
        for (int j = i; j < r; j++) {
            if (distance_calc(points[j]) <= pivot_distance) {
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[r]);
        return i;
    }
    
    int distance_calc(vector<int> point) {
        return (point[0] * point[0]) + (point[1] * point[1]);
    }
};
