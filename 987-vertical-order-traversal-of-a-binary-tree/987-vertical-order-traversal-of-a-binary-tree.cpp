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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int ,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q ;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto node = q.front() ;
            q.pop();
            int x = node.second.first , y = node.second.second ;
            mp[x][y].insert(node.first->val);
            if( node.first->left )
                q.push({node.first->left,{x-1,y+1}});
            if(node.first->right)
                q.push({node.first->right,{x+1,y+1}});
        }
        vector<vector<int>> ans; 
        for(auto it : mp)
        {
            vector<int> col ;
            for(auto val : it.second )
            {
                col.insert(col.end(),val.second.begin(),val.second.end());
            }
            ans.push_back(col);
        }
        return ans; 
    }
};