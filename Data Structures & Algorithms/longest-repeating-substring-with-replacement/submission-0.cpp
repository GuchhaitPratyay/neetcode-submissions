class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;

        int start = 0, end = 0;

        while (end < s.length()) {
            if (s[start] == s[end]) {
                ++end;
            } else {
                if (k != 0) {
                    s[end] = s[start];
                    --k;
                } else {
                    ++start;
                    end = start;
                }
            }
            maxLength = max(maxLength, (end-start));
        }

        return maxLength;
    }
};
