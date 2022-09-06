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
    int preorder(TreeNode *root )
    {
        if( root == NULL ) return 0 ;
        if(root->left == NULL and root->right == NULL ) return root->val;
        int leftNode = preorder(root->left) ;
        int rightNode = preorder(root->right);
        if(leftNode == 0 ) 
            root->left = NULL ;
        if(rightNode == 0 ) 
            root->right = NULL ;
        return leftNode + rightNode + ( root->val == 1 ? 1 : 0) ;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
       if(preorder(root) == 0 )
           return NULL ;
        return root ;
    }
};