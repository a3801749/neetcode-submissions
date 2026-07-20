class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;
        int count = 0;
        int right = 0;
        int left = 0;

        for (int curr = 0; curr < s.size(); curr++) {
            auto it = chars.find(s[curr]);
            string sub = s.substr(left, right - left + 1);
            cout << sub << endl;
            if (it == chars.end() || it->second < left) {
                cout << "no dup" << endl;
                cout << left << endl;
                cout << right << endl;
                count = max(count, right - left + 1);
                chars[s[curr]] = curr;
                right++;
            }
            else {
                cout << "yes dup" << endl;
                left = it->second + 1;
                right = curr + 1;
                it->second = curr;
            }
            cout << count << endl;
            cout << endl;
        }

        return count;
        
    }
};
