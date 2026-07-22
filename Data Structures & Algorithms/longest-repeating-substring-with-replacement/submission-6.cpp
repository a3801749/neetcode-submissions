class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_count = 0;
        int left = 0;
        int right = 0;
        
        char max;
        int num_max = 0;

        vector<int> char_counts;
        char_counts.resize(26);

        int count = 0;

        for (int right = 0; right < s.size(); right++) {

            char_counts[s[right] - 'A']++;

            if (char_counts[s[right] - 'A'] > num_max) {
                max = s[right];
                num_max = char_counts[s[right] - 'A'];
            }

            if ((right - left + 1) - num_max > k) {
                char_counts[s[left] - 'A']--;
                left++;
            }

            max_count = std::max(max_count, right - left + 1);
        }

        return max_count;

    }
};
