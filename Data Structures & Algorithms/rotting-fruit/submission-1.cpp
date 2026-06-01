// 多源 BFS
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int max_row = grid.size();
        int max_col = grid[0].size();
        int tick = 0;
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < max_row; i++){
            for(int j = 0; j < max_col; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        while(!q.empty() && fresh > 0){
            tick++;
            int tick_rotten_num = q.size();
            for(int i = 0; i < tick_rotten_num; i++){
                auto p = q.front();
                q.pop();
                int row = p.first;
                int col = p.second;
                for(int j = 0; j < 4; j++){
                    int new_row = row + dir[j][0];
                    int new_col = col + dir[j][1];
                    if(new_row >= 0 && new_row < max_row && new_col >= 0 && new_col < max_col && grid[new_row][new_col] == 1){
                        grid[new_row][new_col] = 2;
                        fresh--;
                        q.push({new_row, new_col});
                    }    
                }
            }
        }

        if(fresh > 0) return -1;
        else return tick;
    }
};
