class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN ;
        int n = nums.size() ;
        int len = 0 ; 
        int maxEle = *max_element(nums.begin() ,nums.end()) ;
        for(int i = 0 ; i < n ; i++ )
        {
            if( nums[i] == maxEle) len++ ;
            else 
            {
                maxi = max(len,maxi);
                len = 0 ;
            }
        }
        return max(maxi,len) ; 
    }
};