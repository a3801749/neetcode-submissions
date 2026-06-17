class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        while (left < right) {
            while (!isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
                if (left >= s.length()) return true;
            }
            while (!isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
                if (right < 0) return true;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
