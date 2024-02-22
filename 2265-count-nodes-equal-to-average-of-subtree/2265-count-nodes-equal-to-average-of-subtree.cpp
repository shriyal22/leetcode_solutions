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
public:
    int countNodes(TreeNode* root){
        if(!root) return 0;
        return 1 + countNodes(root->left)+ countNodes(root->right);
    }

    int totalSum(TreeNode* root){
        if(!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
         if(!root) return 0;

         int tot = root->val + totalSum(root->left) + totalSum(root->right);
         int nodes = 1 + countNodes(root->left) + countNodes(root->right);

         if(root->val == (tot/nodes)) return 1 + averageOfSubtree(root->left) + averageOfSubtree(root->right);

         return averageOfSubtree(root->left) + averageOfSubtree(root->right);
    }
};