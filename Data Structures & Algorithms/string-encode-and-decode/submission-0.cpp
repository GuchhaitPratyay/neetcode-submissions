class Solution {
public:

    string encode(vector<string>& strs) {
        vector<string> result_str;
        for (string s : strs) {
            result_str.push_back(to_string(s.length()) + '@' + s); 
        }
        string encoding = "";
        for (string s : result_str) {
            encoding += s;
        }
        //cout << encoding;
        return encoding;
    }

    vector<string> decode(string s) {

        vector<string> result;
        for (int i = 0; i < s.length();) {
            int index_of_length = 0;
            int j = i;
            for (; j < s.length(); ++j) {
                if (s[j] == '@') {
                    index_of_length = j;
                    break;
                }
            }
            int len = stoi(s.substr(i, j-i));
            result.push_back(s.substr(j+1, len));
            i += (j-i) + 1 + len; 
        }

        return result;
    }
};
