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
    int count = 0 ; 
        void topdown(TreeNode *root, vector<int> &vec)
        {
            if (root == NULL)
            {
               return  ; 
            }
            vec[root->val]++;
            topdown(root->left, vec);
            topdown(root->right, vec);
            if (root->right == NULL and root->left == NULL) 
            {
                int odd = 0;
                for(int i = 1 ; i < 10 ; i++ )
                {
                    if (vec[i] % 2 == 1) odd++;
                }
                if (odd == 1 or odd == 0 ) count++ ;
                
            }
            
            vec[root->val]--;
        
        }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> vec(10, 0);
        // if (root->right == NULL and root->left == NULL) return 1;
        topdown(root, vec);
        return count ;
    }
};