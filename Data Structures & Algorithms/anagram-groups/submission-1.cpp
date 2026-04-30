class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> groups;

        for (string s : strs) {
            string key(26, 0);

            for (char ch : s) {
                key[ch - 'a']++;
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& [_,value] : groups) {
            result.push_back(value);
        }

        return result;
        //sort(strs.begin(), strs.end());
        //vector<string> temp(strs);
//
        //vector<vector<string>> result;
        //for (int i = 0; i < temp.size(); ++i) {
        //    sort(temp[i].begin(), temp[i].end());
        //    vector<string> subStrs;
        //    if (strs[i] != "done") {
        //          subStrs.push_back(strs[i]);
        //        for (int j = i+1; j < temp.size(); ++j) {
        //            sort(temp[j].begin(), temp[j].end());
        //            if (temp[i] == temp[j]) {
        //            subStrs.push_back(strs[j]);
        //            strs[j] = "done";
        //            }
        //        }
        //        result.push_back(subStrs);
        //    }           
        //}
        //return result;
//
        ////for (string str : strs) {
        //    cout<<str<<" ";
        //}
        //vector<vector<string>> str;
        //return str;
    }
};
