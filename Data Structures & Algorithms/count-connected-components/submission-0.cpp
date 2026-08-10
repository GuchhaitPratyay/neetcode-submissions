class Solution {
private:
    void dfs(int n, int source, vector<vector<int>> &graph, vector<bool> &visitedNodes) {
        //mark the source as visited
        visitedNodes[source] = true;

        //traverse the neighbours for source
        for (auto& neighbour : graph[source]) {

            if (!visitedNodes[neighbour]) {
                dfs(n, neighbour, graph, visitedNodes);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //the number of connected components are nothing but
        //the number of times a BFS or DFS is connected on the graph

        
        vector<bool> visitedNodes(n, false);
        vector<vector<int>> graph(n);

        //form the graph
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }


        int connectedComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visitedNodes[i]) {
                dfs(n, i, graph, visitedNodes);
                ++connectedComponents;
            }
        }

        return connectedComponents;
    }
};
