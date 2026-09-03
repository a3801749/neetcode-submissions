class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int p2 = heights.size()-1;

        int curr_area = -1;

        while (p2 > p1) {
            cout << p1 << " " << p2 << endl;
            int area = abs(p2 - p1) * min(heights[p1], heights[p2]);
            if (area > curr_area) {
                curr_area = area;
            }

            if (heights[p1] < heights[p2]) {
                p1++;
            }
            else if (heights[p1] >= heights[p2]) {
                p2--;
            }

        }

        return curr_area;
    }
};
