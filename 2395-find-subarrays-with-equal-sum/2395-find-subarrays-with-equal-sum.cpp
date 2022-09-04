class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp ;
        int n = nums.size() ;
        for(int i = 0 ; i < n-1 ; i++)
        {
            int val = nums[i] + nums[i+1];
            if(mp[val] )  return true; 
            mp[val]++;
        }
        return false; 
    }
};