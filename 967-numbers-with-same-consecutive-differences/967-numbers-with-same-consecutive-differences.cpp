class Solution {
public:
    void dfs( int n , int k , vector<int> &ans, int curr)
    {
        if( n <= 0 ) 
        {
            ans.push_back(curr);
            return ;
        }
        for(int i = 0 ; i <= 9 ; i++ )
        {
            if(curr== 0 and i==0) continue ;
            else if( curr == 0 and i != 0 )
            {
                dfs(n-1,k,ans,i);
            }
            else if( abs((curr % 10) - i) == k)
            {
                dfs(n-1,k,ans,curr*10+i);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans ;
        if( n == 1 ) ans.push_back(0);
        dfs(n,k,ans,0);
        return ans;
    }
};