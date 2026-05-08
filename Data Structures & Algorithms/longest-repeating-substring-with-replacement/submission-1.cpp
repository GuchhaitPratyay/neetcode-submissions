class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int i = 0;
        int maxFrequency = 0;
        int result = 0;

        for (int j = 0; j < s.length(); ++j) {
            count[s[j] - 'A']++;

            maxFrequency = max(maxFrequency, count[s[j] - 'A']);

            // shrink the window if it is invalid
            while ((j - i + 1) - maxFrequency > k) {
                count[s[i] - 'A']--;
                ++i;
            }

            result = max(result, (j-i)+1);
        }
        
        return result;
        //int maxLength = 0;
//
        //int start = 0, end = 0;
//
        //while (end < s.length()) {
        //    if (s[start] == s[end]) {
        //        ++end;
        //    } else {
        //        if (k != 0) {
        //            s[end] = s[start];
        //            --k;
        //        } else {
        //            ++start;
        //            end = start;
        //        }
        //    }
        //    maxLength = max(maxLength, (end-start));
        //}
//
        //return maxLength;
    }
};
