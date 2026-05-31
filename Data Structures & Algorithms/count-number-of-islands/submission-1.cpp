// 依序 scan，找到 1 遍進行 DFS 將相鄰的 1 變為 0 後，再重新 scan
class Solution {
private:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int grid_row_size;
    int grid_col_size;
    void dfsReplace(vector<vector<char>>& grid, int row, int col){
        if(row >= grid_row_size || row < 0 || col >= grid_col_size || col < 0 || grid[row][col] != '1'){
            return;
        }
        else{
            grid[row][col] = '0';
            for(int i = 0; i < 4; i++){
                int new_row = row + dir[i][0];
                int new_col = col + dir[i][1];
                dfsReplace(grid, new_row, new_col);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        grid_row_size = grid.size();
        grid_col_size = grid[0].size();
        int count = 0;
        for(int i = 0; i < grid_row_size; i++){
            for(int j = 0; j < grid_col_size; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfsReplace(grid, i, j);
                }
            }
        }
        return count;
    }
};
