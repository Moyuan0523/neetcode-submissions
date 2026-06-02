class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m + 2, vector<int>(n + 2, 0));
        grid[m][n] = 1;
        
        for(int i = m; i > 0; i--){
            for(int j = n; j > 0; j--){
                if(i == m && j == n) continue;
                grid[i][j] = grid[i + 1][j] + grid[i][j+1];
            }
        }

        return grid[1][1];
    }
};
