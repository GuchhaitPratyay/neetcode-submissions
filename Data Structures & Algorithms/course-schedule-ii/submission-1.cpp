class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courseOrder;
        //Prepare a adjacency list from the prerequisite
        vector<vector<int>> adjacencyList(numCourses);
        //Declare a vector to track the in-degree of all the nodes
        vector<int> inDegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); ++i) {
            adjacencyList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]] += 1;
        }

        //use a queue to store the nodes which has in-degree as 0
        queue<int> tempStorage;

        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                tempStorage.push(i);
            }
        }

        while (!tempStorage.empty()) {
            int node = tempStorage.front();
            courseOrder.push_back(node);
            tempStorage.pop();

            for (auto& neighbour : adjacencyList[node]) {
                inDegree[neighbour] -= 1;
                if (inDegree[neighbour] == 0) {
                    tempStorage.push(neighbour);
                }
            }
        }

        if (courseOrder.size() != numCourses) {
            return {};
        }

        return courseOrder;
    }
};
