class Solution {
public:
    void topdown(vector<int> &candidates , int i , int target , vector<vector<int>> &ans  , vector<int> &res )
    {
        if( i == candidates.size()  )
        {
            return ;
        }
        if( target == 0 )
        {
            ans.push_back(res);
            return ;
        }
        if( target >= candidates[i]  )
        {
            res.push_back(candidates[i]);
            topdown(candidates, i , target - candidates[i] , ans ,res );            
            res.pop_back();
        }
        topdown(candidates, i+1 ,target , ans,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> res ;
        topdown(candidates,0,target,ans,res);
        return ans; 
    }
};