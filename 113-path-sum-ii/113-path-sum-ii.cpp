/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void dfs(TreeNode *root, int targetSum, vector<vector < int>> &ans, vector< int > &temp)
        {
            if (root == NULL) return;
            // if (targetSum <= 0) return;
            if (root->left == NULL and root->right == NULL )
            {
                
                int val = targetSum - root->val;
                // cout<<val<<endl;
                if (val == 0)
                {
                    temp.push_back(root->val);
                    ans.push_back(temp);
                    temp.pop_back();
                }
                return;
            }
            temp.push_back(root->val);

            dfs(root->left, targetSum - root->val, ans, temp);
            temp.pop_back();
            temp.push_back(root->val);
            dfs(root->right, targetSum - root->val, ans, temp);
            temp.pop_back();
            
        }
    vector<vector < int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector < int>> ans;
        vector<int> temp;
        dfs(root, targetSum, ans, temp);
        return ans;
    }
};