class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text1.size();
        int col = text2.size();
        vector<char> text1_c(text1.begin(), text1.end());
        vector<char> text2_c(text2.begin(), text2.end());

        vector<vector<int>> grid(row + 1, vector<int>(col + 1, 0));
        for(int i = 1; i < row + 1; i++){
            for(int j = 1; j < col + 1; j++){
                // 因為 grid 是 1-indexed，對應到 string 時要減 1
                if (text1[i - 1] == text2[j - 1]) {
                    // 字元相同：由左上方（對角線）轉移過來並 +1
                    grid[i][j] = grid[i - 1][j - 1] + 1;
                } else {
                    // 字元不同：取上方或左方的最大值
                    grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[row][col];
    }
};
