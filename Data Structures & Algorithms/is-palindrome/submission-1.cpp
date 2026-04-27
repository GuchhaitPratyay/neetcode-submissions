class Solution {
public:
    bool isPalindrome(string s) {
        for (int i=0; i<s.length();) {
            if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9')) {
                s.erase(i, 1);
            } else {
                i++;
            }
        }
        //for (auto it=s.begin(); it!=s.end(); ++it) {

        //}

        //cout<<s;
        char* start = &s[0];
        char* end = &(s[s.length()-1]);
        
        while (start < end) {
            if (tolower(*start) != tolower(*end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
