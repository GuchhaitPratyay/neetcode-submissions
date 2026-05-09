class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        const string& a = strs.front();
        const string& b = strs.back();
        int i = 0;
        while (i < (int)min(a.size(), b.size()) && a[i] == b[i]) ++i;
        return a.substr(0, i);
    }
};