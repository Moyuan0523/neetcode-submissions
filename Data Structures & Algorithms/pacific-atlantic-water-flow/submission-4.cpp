// 從邊邊緣往回 dfs，能搜到的就可以流到該海域，可以留到兩海域的就是 answer
class Solution {
private:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<int>>& heights, int prev, int row, int col, set<pair<int, int>>& ocean){
        // 在範圍內且比上一位低才能流過去
        if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size() || ocean.count({row, col}) || heights[row][col] < prev){ 
            return;
        }
        else{
            ocean.insert({row, col});
            for(int i = 0; i < 4; i++){
                int new_row = row + dir[i][0];
                int new_col = col + dir[i][1];
                dfs(heights, heights[row][col], new_row, new_col, ocean);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        set<pair<int, int>> pac;
        set<pair<int, int>> atl;
        int max_row = heights.size();
        int max_col = heights[0].size();
        // 上下
        for(int col = 0; col < max_col; col++){
            dfs(heights, -1, 0, col, pac);
            dfs(heights, -1, max_row - 1, col, atl);
        }
        // 左右
        for(int row = 0; row < max_row; row++){
            dfs(heights, -1, row, 0, pac);
            dfs(heights, -1, row, max_col - 1, atl);
        }
        
        // intersection
        for(auto h : pac){
            if(atl.count(h)){
                result.push_back({h.first, h.second});
            }
        }
        return result;
    }
};
