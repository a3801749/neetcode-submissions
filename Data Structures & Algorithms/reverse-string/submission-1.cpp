class Solution {
public:
    void reverseString(vector<char>& s) {
        auto it1 = s.begin();
        auto it2 = s.end();
        it2--;

        for (int i = 0; i < s.size() / 2; i++) {
            std::swap(*it1, *it2);
            it1++;
            it2--;
        }
        
    }
};