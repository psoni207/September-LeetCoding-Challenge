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
    int res = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        helperSolve(root, 0);
        return res;
    }
    
    void helperSolve(TreeNode* root, int num){
        if(root == NULL){
            return;
        }
        if(!root->left && !root->right){
            res += num * 2 + (root->val) * 1;
        }
        
        int x = root->val;
        helperSolve(root->left, num * 2 + x * 1);
        helperSolve(root->right, num * 2 + x * 1);
    }
    
};