class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //calculate number of in-degree of all the nodes
        //Prepare a directed graph
        vector<vector<int>> adjacency(numCourses);
        vector<int> inDegree(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i) {
            adjacency[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDegree[prerequisites[i][1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            //traverse its neighbours 
            for (auto& neighbour : adjacency[node]) {
                inDegree[neighbour] -= 1;
                if (inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] > 0) {
                return false;
            }
        }

        return true;
    }
};
