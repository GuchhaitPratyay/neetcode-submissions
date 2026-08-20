class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //Intuition:
        //We need to perform a topological sort to provide the order in which the courses must be taken

        //I need to create a graph and also while creation I need to maintain inDegree vector
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> result;

        for (auto element : prerequisites) {
            adjList[element[1]].push_back(element[0]);
            inDegree[element[0]]++;
        }

        //maintain a queue to perform a bfs traversal,
        //nodes having 0 in degree should be processed first
        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            

            for (int neighbour : adjList[node]) {
                inDegree[neighbour] -= 1;
                if (inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};
