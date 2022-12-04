class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int balance = 0 ;
        unordered_map<int,int> mp ; 
        mp[0] = 1 ; 
        bool flag = false ;
        int ans = 0 ;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            if( nums[i] < k ) balance-- ;
            else if( nums[i] > k ) balance++ ;
            else if( nums[i] == k ) flag = true ;
            
            if( flag )
            {
                ans += mp[balance] + mp[balance -1 ] ;
                
            }
            else 
                mp[balance]++ ; 
        }
        return ans ;
    }
};