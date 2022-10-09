/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> preorder;
    void inorder(TreeNode *root, int k)
    {
        if (root == NULL) return;
        preorder.push_back(root->val);
        inorder(root->left, k);
        inorder(root->right, k);
        return;
    }
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root, k);
        unordered_map<int, int> mp;
        int n = preorder.size();
        for (int i = 0; i < n; i++)
        {
            int val = k - preorder[i];
            if (mp.find(preorder[i]) != mp.end() )
            {
                return true;
            }
            mp[val] = 1 ;
           
        }
        return false;
    }
};