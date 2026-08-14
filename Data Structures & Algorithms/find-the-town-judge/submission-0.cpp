class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //prepare a indegree array
        vector<int> inDegree(n+1, 0);

        for (int i = 0; i < trust.size(); ++i) {
            inDegree[trust[i][1]] += 1;
        }

        int counter = 0;
        int answer = -1;
        for (int i = 1; i < n+1; ++i) {
            if (inDegree[i] == 0) {
                counter++;                
            }
            if (inDegree[i] >= n-1) answer = i;
        }

        return counter < n-1 ? -1 : answer;
    }
};