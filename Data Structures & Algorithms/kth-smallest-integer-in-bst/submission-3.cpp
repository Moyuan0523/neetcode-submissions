/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 使用 Inoder traversal，紀錄拜訪第幾個，印出第 k 個 node->val
class Solution {
private:
    int result;
    int count = 0;
    void dfs(TreeNode* node, int k){
        if(!node || count > k) return;
        dfs(node->left, k);

        count++;
        if(count == k){
            result = node->val;
            return;
        }

        dfs(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return result;
    }
};
