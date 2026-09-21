class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        int freq_s1[26] = {};
        for (int i = 0; i < s1.size(); i++) {
            freq_s1[s1[i]-97] += 1;
        }

        int freq_s2_substr[26] = {};
        for (int i = 0; i < s1.size(); i++) {
            freq_s2_substr[s2[i]-97] += 1;
        }

        int substr_end = s1.size()-1;
        int substr_beg = 0;
        while (substr_end < s2.size()) {
            bool found = true;
            for (int i = substr_beg; i <= substr_end; i++) {
                if ((freq_s2_substr[s2[i]-97] != freq_s1[s2[i]-97]) ||
                    (freq_s1[s2[i]-97] == 0)) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
            else if (substr_end == s2.size()-1) {
                return false;
            }
            else {
                freq_s2_substr[s2[substr_beg]-97] -= 1;
                substr_beg++;
                substr_end++;
                freq_s2_substr[s2[substr_end]-97] += 1;
            }
        }
        return false;


    }
};
