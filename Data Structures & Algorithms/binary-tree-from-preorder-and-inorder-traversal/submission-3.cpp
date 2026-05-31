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

// 從 pre 得到 root，從 inorder 得到左子樹數量
class Solution {
private:
    unordered_map<int, int> inordered_map;
    TreeNode* build(vector<int>& preorder, int pre_index, int in_start, int in_end){
        if(in_start > in_end) return nullptr;
        TreeNode* node = new TreeNode();

        // 左右子樹
        int in_index = inordered_map[preorder[pre_index]];
        int left_node_num = in_index - in_start;

        node->val = preorder[pre_index];
        node->left = build(preorder, pre_index + 1, in_start, in_index - 1);
        node->right = build(preorder, pre_index + left_node_num + 1, in_index + 1, in_end);

        return node; 
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inordered_map[inorder[i]] = i;
        }
        return build(preorder, 0, 0, n-1);
    }
};
