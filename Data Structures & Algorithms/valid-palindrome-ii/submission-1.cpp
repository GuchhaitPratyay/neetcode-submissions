class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.length()-1;
        int skipCount = 1;
        while (start <= end) {
            if (s[start] != s[end]) {
                if (s[start+1] == s[end] && skipCount > 0) {
                    ++start;
                    --skipCount;
                } else if (s[start] == s[end-1] && skipCount > 0) {
                    --end;
                    --skipCount;
                } else {
                    return false;
                }
            } else {
                ++start;
                --end;
            }
        }
        return true;
    }
};