class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());
        vector<string> temp(strs);

        vector<vector<string>> result;
        for (int i = 0; i < temp.size(); ++i) {
            sort(temp[i].begin(), temp[i].end());
            vector<string> subStrs;
            if (strs[i] != "done") {
                  subStrs.push_back(strs[i]);
                for (int j = i+1; j < temp.size(); ++j) {
                    sort(temp[j].begin(), temp[j].end());
                    if (temp[i] == temp[j]) {
                    subStrs.push_back(strs[j]);
                    strs[j] = "done";
                    }
                }
                result.push_back(subStrs);
            }           
        }
        return result;

        //for (string str : strs) {
        //    cout<<str<<" ";
        //}
        //vector<vector<string>> str;
        //return str;
    }
};
