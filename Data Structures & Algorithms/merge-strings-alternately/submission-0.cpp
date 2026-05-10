class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        result.reserve(word1.size() + word2.size());
        int i = 0, j = 0;

        while (i < word1.length() && j < word2.length()) {
            result += word1[i++];
            result += word2[j++];
        }
        
        if (i < word1.length()) {
            result += word1.substr(i, word1.length()-i);
        }
        if (j < word2.length()) {
            result += word2.substr(j, word2.length()-j);
        }

        return result;
    }
};