class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int windowSize = s1.length();
        unordered_map<char, int> myMap;
        int end = 0, start = 0;

        for (auto& ch : s1) {
            myMap[ch]++;
        }
        int distinctCount = myMap.size();

        while (end < s2.length()) {
            if (myMap.count(s2[end])) {
                --myMap[s2[end]];
                if (myMap[s2[end]] == 0) --distinctCount;
            }
            if (end-start+1 < windowSize) {
                ++end;
            } else if (end-start+1 == windowSize) {
                if (distinctCount == 0) return true;
                if (myMap.count(s2[start])) {
                    myMap[s2[start]]++;
                    if (myMap[s2[start]] == 1) ++distinctCount;
                }
                ++start;
                ++end;
            }
        }

        return false;
    }
};
