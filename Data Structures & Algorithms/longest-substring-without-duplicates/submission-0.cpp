class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        int maxLen = 1, start = 0, end = 0;
        unordered_map<char, int> table;

        while (end < s.length()) {
            if (table.count(s[end]) == 0) {
                table[s[end]]++;
            } else {
                start = end;
            }
            maxLen = max(maxLen, end-start+1);
            ++end;
        }
        return maxLen;
    }
};
