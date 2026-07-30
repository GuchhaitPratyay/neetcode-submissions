class Solution {
private:
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visitedGrid, int rowIndex, int columnIndex) {
        int rows = grid.size();
        int columns = grid[0].size();
        int area = 0;

        vector<vector<int>> neighbours = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        queue<pair<int, int>> q;
        
        //Add {i,j} pair into the queue and mark them as visited
        visitedGrid[rowIndex][columnIndex] = true;
        q.push({rowIndex, columnIndex});
        //Add the 1 to the area as it is not considered in further areas calculation
        area++;

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            //remove the element form the queue
            q.pop();

            //check it's neighbour, if they are one
            for (auto& it : neighbours) {
                //By adding delta, we will get the new row and column
                int rowIndex = x + it[0], columnIndex = y + it[1];
                
                if (rowIndex >= 0 && columnIndex >= 0 && rowIndex < rows && columnIndex < columns 
                    && grid[rowIndex][columnIndex] == 1 && !visitedGrid[rowIndex][columnIndex]) {
                    visitedGrid[rowIndex][columnIndex] = true;
                    q.push({rowIndex, columnIndex});
                    area++;
                }
            }

        }

        return area;

        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        vector<vector<bool>> visitedGrid(grid.size(), vector<bool>(grid[0].size(), false));
        int areaOfIsland = 0;

        for (int rowIndex = 0; rowIndex < grid.size(); ++rowIndex) {
            for (int columnIndex = 0; columnIndex < grid[0].size(); ++columnIndex) {
                if (!visitedGrid[rowIndex][columnIndex] && grid[rowIndex][columnIndex] == 1)
                    areaOfIsland = max(areaOfIsland, bfs(grid, visitedGrid, rowIndex, columnIndex));
            }
        }
        
        return areaOfIsland;
    }
};
