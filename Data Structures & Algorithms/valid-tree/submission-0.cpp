class Solution {
private:
    bool dfs(int source, int parent, vector<vector<int>> &adjacencyList, vector<bool> &visitedNodes) {
        visitedNodes[source] = true;

        for (auto& neighbour : adjacencyList[source]) {
            if (!visitedNodes[neighbour]) {
                dfs(neighbour, source, adjacencyList, visitedNodes);
            } else {
                if (neighbour != parent) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        bool isValidTree = false;
        //prepare a adjacency list to represent a graph
        vector<vector<int>> adjacencyList(n);

        for (int i = 0; i < edges.size(); ++i) {
            adjacencyList[edges[i][0]].push_back(edges[i][1]);
            adjacencyList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visitedNodes(n);

        for (int i = 0; i < n; ++i) {
            if (!visitedNodes[i]) {
                isValidTree = dfs(i, -1, adjacencyList, visitedNodes);
                if (!isValidTree) return false;
            }            
        }

        return true;
    }
};
