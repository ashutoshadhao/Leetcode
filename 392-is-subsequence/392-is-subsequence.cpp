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
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return topdown(s,t,0,0,dp);
    }
};