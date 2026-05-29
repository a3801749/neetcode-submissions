class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> s;
        int i1 = 0;
        int i2 = 0;
        int sum = 0;
        s.reserve(operations.size());


        for (string str : operations) {
            if (str == "C") {
                sum -= i1;
                s.pop_back();
                if (s.size() == 1) {
                    i1 = s[0];
                    i2 = 0;
                }
                else if (s.size() == 0) {
                    i1 = 0;
                    i2 = 0;
                }
                else {
                i1 = s[s.size()-1];
                i2 = s[s.size()-2]; }
            }
            else if (str == "D") {
                s.push_back(i1 * 2);
                i2 = i1;
                i1 *= 2;
                sum += i1;
            }
            else if (str == "+") {
                int temp = i1 + i2;
                s.push_back(temp);
                i2 = i1;
                i1 = temp;
                sum += i1;
            }
            else {
                s.push_back(stoi(str));
                i2 = i1;
                i1 = s[s.size()-1];
                sum += i1;
            }
        }

        return sum;

    }
};