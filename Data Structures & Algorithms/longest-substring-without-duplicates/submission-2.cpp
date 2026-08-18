class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int longestSubstring = 1;

        unordered_map<char, int> table;

        int start = 0, end = 0;

        while (end <= s.length()-1) {
            //check if the the character which is comming is allready present in the map
            if (table.count(s[end]) == 0) {
                table[s[end]] += 1;
                end++;
            } else {
                table.erase(s[start]);
                start++;
            }
            longestSubstring = max(longestSubstring, (end-start));
        }

        return longestSubstring;
    }
};
