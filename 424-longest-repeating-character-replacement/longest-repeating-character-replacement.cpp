class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxLength = 0;
        int maxFreq = 0;

        unordered_map<char, int> freq;

        for (int r = 0; r < s.length(); r++) {

            freq[s[r]]++;

            // Maximum frequency of one character in current window
            maxFreq = max(maxFreq, freq[s[r]]);

            // Characters that need to be replaced
            int replacements = (r - l + 1) - maxFreq;

            // If replacements > k, shrink the window
            while (replacements > k) {
                freq[s[l]]--;
                l++;

                replacements = (r - l + 1) - maxFreq;
            }

            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};