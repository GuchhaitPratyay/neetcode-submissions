class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "" || t.size() > s.size()) {
            return "";
        }

        //I will need a hasmap to track how many characters are there in t string and what are there occurrence ferquency
        unordered_map<char, int> tTable, sTable;

        //loop over the t string to get the table filled
        for (auto& ch : t) {
            tTable[ch]++;
        }

        int left = 0, right = 0;
        int minLength = INT32_MAX;
        int windowHaving = 0;
        int windowNeeding = tTable.size();
        //I need to track the index of the start window, for the least window length
        pair<int, int> windowIndex = {-1, -1};

        while (right < s.size()) {

            //start adding the characters into the map
            sTable[s[right]]++;
            
            //I will increament the having count
            if (tTable.count(s[right]) && sTable[s[right]] == tTable[s[right]]) {
                ++windowHaving;
            }

            //At one point the having window will have all the characters needed to accomadate t string
            while (windowHaving == windowNeeding) {
                if (right - left + 1 < minLength) {
                    //We will get a possible answer
                    minLength = right - left + 1;
                    windowIndex = {left, right};
                }
                //start decrementing the character counts from the sTable
                sTable[s[left]]--;
                //Check whether we are somewhere diverting from the actual contraints
                if (tTable.count(s[left]) && sTable[s[left]] < tTable[s[left]]) {
                    --windowHaving;
                }
                ++left;

            }

            ++right;
        }

        return minLength == INT32_MAX ? "" : s.substr(windowIndex.first, minLength);
    }
};
