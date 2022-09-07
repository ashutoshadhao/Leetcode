class Solution {
public:
    bool topdown( string s, string t ,int i , int j )
    {
        // if( i == s.size() and j == t.size() )
        //     return true ;
        if( i == s.size() ) return true;
        if( j == t.size() ) return false ;
        if( s[i] == t[j] ) 
            return topdown(s,t,i+1,j+1);
        return topdown(s,t,i,j+1);
    }
    bool isSubsequence(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return topdown(s,t,0,0);
    }
};