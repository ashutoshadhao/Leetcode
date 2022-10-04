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
    bool preorder( TreeNode * root ,int targetSum )
    {
        if(root == NULL ) return false ;
        if( root->left == NULL and  root->right == NULL and targetSum - root->val == 0 ) return true ;
        
        bool left =  preorder(root->left,targetSum-root->val ); 
        bool right = preorder(root->right,targetSum - root->val);
        return left or right ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL ) return false ;
        return preorder(root,targetSum) ;
    }
};