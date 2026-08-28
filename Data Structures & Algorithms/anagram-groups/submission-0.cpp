class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> anagram_helper;

        for (string str : strs) {
            
            vector<int> chars;
            chars.resize(26);

            for (char c : str) {
                chars[c - 97] += 1;
            }

            auto it = anagram_helper.find(chars);
            if (it != anagram_helper.end()) {
                it->second.push_back(str);
            }
            else {
                vector<string> v;
                v.push_back(str);
                anagram_helper.insert({chars, v});
            }

        }

        vector<vector<string>> result;

        for (const auto& [key, value] : anagram_helper) {
            result.push_back(value);
        }

        return result;

    }
};
