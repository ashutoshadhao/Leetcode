/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* preorder(TreeNode *root, int val, int depth, bool isLeft)
        {

            if (depth == 1)
            {
                TreeNode *left = isLeft ? root : NULL;
                TreeNode *right = isLeft ? NULL : root;
                return new TreeNode(val, left, right);
            }
            if (root)
            {
                root->left = preorder(root->left, val, depth - 1, true);
                root->right = preorder(root->right, val, depth-1, false);
            }
            return root;
        }
    TreeNode* addOneRow(TreeNode *root, int val, int depth)
    {

        return preorder(root, val, depth, true);
    }
};