class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> neighbour = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        //start our traversal from each treasure chest to its neighbouring lands
        // and update the path
        //Simplly do BFS traversal because in ideal case it gives to shortest path to each land
        //We have to do BFS traversal for all the nodes one by one because we have
        int row = grid.size();
        int column = grid[0].size();
        //prepare a visited array
        //vector<vector<bool>> visitedGrid(n, )
        queue<pair<int, int>> q;

        //traverse the gird and push all the treasure chest the queue
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == 0) {
                    //it is the treasure chest
                    q.push({i,j});
                }
            }
        }

        //maintain a counter track the level
        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int rowCod = q.front().first;
                int colCod = q.front().second;
                q.pop();

                for (auto& a : neighbour) {
                    int newRow = rowCod + a[0], newCol = colCod + a[1];

                    if (newRow >= 0 && newCol >= 0 && newRow < row && newCol < column) {
                        if (grid[newRow][newCol] == 2147483647) {                            
                            grid[newRow][newCol] = level;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }

            level++;
        }
    }
};
