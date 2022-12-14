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
    vector<TreeNode*> solve( int n ,  unordered_map<int,vector<TreeNode*>> &dp )
    {
        vector<TreeNode*> ans ;
        if( n == 1 ) 
        {
            TreeNode *root = new TreeNode(0) ;
            ans.push_back(root);
            return ans ;
        }
        if(dp.find(n) != dp.end() ) return dp[n] ;
        for( int i = 1 ; i < n ; i = i+2)
        {
            vector<TreeNode*> left = solve(i,dp);
            vector<TreeNode*> right = solve(n-i-1,dp);
            for(auto l : left )
            {
                for(auto r : right )
                {
                    TreeNode *root = new TreeNode(0) ;
                    root->left = l ;
                    root->right = r ;
                    ans.push_back(root) ; 
                }
            }
            
        }
        return dp[n] = ans; 
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> dp ; 
        return solve(n,dp);
    }
};