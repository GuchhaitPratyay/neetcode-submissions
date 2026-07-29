class Solution {
private:
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visitedGrid, int rowIndex, int columnIndex) {

        int rows = grid.size();
        int columns = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> coordinates = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        
        visitedGrid[rowIndex][columnIndex] = true;
        q.push({rowIndex, columnIndex});

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for (auto& direction : coordinates) {
                int rowNew = x + direction[0], colNew = y + direction[1];
                if (rowNew >= 0 && rowNew < rows && colNew >= 0 && colNew < columns
                    && grid[rowNew][colNew] == '1' && !visitedGrid[rowNew][colNew] ) {
                    visitedGrid[rowNew][colNew] = true;
                    q.push({rowNew,colNew});
                }
            }
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>> visitedGrid(rows, vector<bool>(columns, false));

        int numberOfIslands = 0;

        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            for (int colIndex = 0; colIndex < columns; ++colIndex) {
                if (!visitedGrid[rowIndex][colIndex] && grid[rowIndex][colIndex] == '1') {
                    ++numberOfIslands;
                    bfs(grid, visitedGrid, rowIndex, colIndex);
                }
            }
        }
        return numberOfIslands;
    }
};
