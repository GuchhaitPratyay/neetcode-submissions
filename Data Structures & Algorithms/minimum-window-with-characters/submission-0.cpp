class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dictionary;
        string result = "";
        int end = 0, start = 0;
        string resultString = "";
        int minWindowSize = INT32_MAX;

        for (auto& ch: t) {
            dictionary[ch]++;
        }
        int uniqueCharCount = dictionary.size();
        while (end < s.length()) {
            if (dictionary.count(s[end])) {
                dictionary[s[end]]--;
                if (dictionary[s[end]] == 0) --uniqueCharCount;
            }

            if (uniqueCharCount == 0) {
                while (uniqueCharCount == 0) {
                    if (dictionary.count(s[start])) {
                        dictionary[s[start]]++;
                        if (dictionary[s[start]] == 1) {
                            ++uniqueCharCount;                            
                        }
                        minWindowSize = min(minWindowSize, end-start+1);
                    }
                    ++start;
                }
            }
            ++end;
        }

        if (minWindowSize == INT32_MAX) return "";
        return s.substr(start-1, minWindowSize); 
    }
};
