class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // create a neighbour vector
        vector<vector<int>> neighbour = {{-1,0}, {0, 1}, {1,0}, {0,-1}};

        int rows = grid.size(), columns = grid[0].size();
        // Need to maintain an queue to store the coordinates of the rotten oranges
        queue<pair<int, int>> rottenFruit;

        //iterate over the grid and push the rotten cell to queue
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == 2) {
                    rottenFruit.push({i,j});
                }
            }
        }

        int minutes = -1;

        //Start a BFS traversal
        while (!rottenFruit.empty()) {
            int size = rottenFruit.size();
            //int level = 0;
            //Do not travel the other nodes until one level is finished 
            //The number of levels will give me minutes
            while (size--) {
                int rowCod = rottenFruit.front().first;
                int colCod = rottenFruit.front().second;
                rottenFruit.pop();
                for (int i = 0; i < 4; ++i) {
                    int newRow = rowCod + neighbour[i][0];
                    int newCol = colCod + neighbour[i][1];

                    if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < columns) {
                        if (grid[newRow][newCol] == 1) {
                            rottenFruit.push({newRow,newCol});
                            grid[newRow][newCol] = 2;
                            //level = 1;
                        }
                    }
                }
            }
            minutes += 1;
        }

        //Traverse the complete grid again to check any fresh fruits are present
        for (auto& v : grid) {
            for (auto& i : v) {
                if (i == 1) return -1;
            }
        }

        return minutes;
    }
};
