class Solution {
public:
    bool topdown( string s, string t ,int i , int j , vector<vector<int>> &dp)
    {
        
        if( i == s.size() ) return true;
        if( j == t.size() ) return false ;
        if(dp[i][j]!=-1) return dp[i][j];
        if( s[i] == t[j] ) 
            return dp[i][j] = topdown(s,t,i+1,j+1,dp);
        return dp[i][j] = topdown(s,t,i,j+1,dp);
    }
    bool isSubsequence(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        for(int i = n ; i >= 0 ; i-- )
        {
            for(int j = m ; j >= 0 ; j-- )
            {
                if( i == s.size() ) dp[i][j] =  true;
               else if( j == t.size() ) dp[i][j] =  false ;
               else if( s[i] == t[j] ) 
                     dp[i][j] =dp[i+1][j+1];
               else  dp[i][j] = dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};