class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> anagram_helper;

        for (string str : strs) {
            
            vector<int> chars;
            chars.resize(26);

            for (char c : str) {
                chars[c - 97] += 1;
            }

            string key = to_string(chars[0]);
            for (int i = 1; i < 26; i++) {
                key += "," + to_string(chars[i]);
            }

            anagram_helper[key].push_back(str);
        }

        vector<vector<string>> result;

        for (const auto& [key, value] : anagram_helper) {
            result.push_back(value);
        }

        return result;

    }
};
