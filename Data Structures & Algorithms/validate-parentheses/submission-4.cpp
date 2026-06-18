class Solution {
public:
    bool isValid(string s) {
        deque<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{') {
                st.push_back('}');
            }
            else if (s[i] == '[') {
                st.push_back(']');
            }
            else if (s[i] == '(') {
                st.push_back(')');
            }
            else if (st.empty() || s[i] != st.back()) {
                return false;
            }
            else st.pop_back();
        }
        return st.empty();
    }
};
