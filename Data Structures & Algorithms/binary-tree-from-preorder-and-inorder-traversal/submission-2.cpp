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

class Solution {
private:
    unordered_map<int, int> inordered_map;
    vector<int> pre;
    TreeNode* build(int pre_index, int in_start, int in_end){
        if(in_start > in_end) return nullptr;

        // 計算左右子樹 node 數量
        int in_index = inordered_map[pre[pre_index]];
        int left_node_num = in_index - in_start; 

        TreeNode* node = new TreeNode();
        node->val = pre[pre_index];
        node->left = build(pre_index + 1, in_start, in_index - 1);
        node->right = build(pre_index + left_node_num + 1, in_index + 1, in_end);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inordered_map[inorder[i]] = i;
        }
        return build(0, 0, n -1);
    }
};
