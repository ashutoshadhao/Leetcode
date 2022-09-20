class Solution {
public:

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size() ;
        vector<int> dp(m+1,0);
        int ans = 0 ;
        for( int i = 0 ; i <= n ; i++)
        {
             vector<int> temp(m+1,0);
            for( int j =0 ; j  <= m; j++)
            {
                if( i == 0 or j ==0 ) temp[j] = 0 ;
                else if( nums1[i-1] == nums2[j-1] )
                {
                    temp[j] = 1 + dp[j-1];
                    ans = max(temp[j],ans);
                }
                else 
                {
                    temp[j] = 0 ;
                }
            }
            dp = temp ;
        }
        return ans; 
    }
};