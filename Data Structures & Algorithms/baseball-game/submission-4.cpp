class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> s;
        int sum = 0;
        s.reserve(operations.size());


        for (string str : operations) {
            if (str == "C") {
                sum -= s.back();
                s.pop_back();
            }
            else if (str == "D") {
                s.push_back(s.back() * 2);
                sum += s.back();
            }
            else if (str == "+") {
                s.push_back(s[s.size()-1] + s[s.size()-2]);
                sum += s.back();
            }
            else {
                s.push_back(stoi(str));
                sum += s.back();
            }
        }

        return sum;

    }
};