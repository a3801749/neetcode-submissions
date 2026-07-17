class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result(word1.size() + word2.size(), ' ');
        int i = 0;
        for ( ; ((i/2) < word1.size()) && ((i/2) < word2.size()); i++) {
            if (i % 2 == 0) {
                result[i] = word1[i/2];
            }
            else result[i] = word2[i/2];
        }

        int current = i/2;

        if ((i/2) < word1.size()) {
            for ( ; current < word1.size(); i++) {
                result[i] = word1[current];
                current++;
            }
        }
        else {
            for ( ; current < word2.size(); i++) {
                result[i] = word2[current];
                current++;
            }
        }
        return result;
    }
};