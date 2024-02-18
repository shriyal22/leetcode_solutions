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
    TreeNode *func(vector<int> preOrder, int &i, long long int maxi){
        if(i==preOrder.size() || preOrder[i] >maxi) return NULL;
        TreeNode* root = new TreeNode(preOrder[i]);
        i++;
        root->left = func(preOrder, i, root->val);
        root->right = func(preOrder, i, maxi);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preOrder) {
        int i=0;
        return func(preOrder, i, INT_MAX);
    }
};