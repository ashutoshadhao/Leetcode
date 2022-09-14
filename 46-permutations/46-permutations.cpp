class Solution {
public:
    void topdown(vector<int>&nums, int i , vector<vector<int>> &ans )
    {
        if(i == nums.size()) 
        {
            ans.push_back(nums);
            return ;
        }
        for(int ind = i ; ind < nums.size() ; ind++ )
        {
            swap(nums[i],nums[ind]);
            topdown(nums,i+1,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        topdown(nums,0,ans);
        return ans; 
    }
};