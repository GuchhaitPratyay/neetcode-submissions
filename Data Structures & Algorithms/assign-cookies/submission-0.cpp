class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //Intution
        //sort both arrays
        //int satisfiedChild = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int greedIndex = 0, cookieIndex = 0;

        while (greedIndex < g.size() && cookieIndex < s.size()) {
            if (s[cookieIndex] >= g[greedIndex]) {
                //++satisfiedChild;
                ++cookieIndex;
                ++greedIndex;
            } else {
                ++cookieIndex;
            }
        }

        return greedIndex;
    }
};