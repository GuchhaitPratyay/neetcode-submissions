class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Basically I neeed to track the incoming edges and outgoing edges
        //Track the forward and backward neighbour of the people
        vector<int> forwardNeighbour(n+1);
        vector<int> backwardNeighbour(n+1);

        for (int i = 0; i < trust.size(); ++i) {
            forwardNeighbour[trust[i][0]]++;
            backwardNeighbour[trust[i][1]]++;
        }
        
        //traverse both the vectors
        for (int i = 1; i <= n; ++i) {
            // judge will be the person who has 0 outgoing edges and n-1 incomming edges
            if (forwardNeighbour[i] == 0 && backwardNeighbour[i] == n-1) {
                return i;
            }
        }

        return -1;
    }
};