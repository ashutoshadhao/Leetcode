class Solution {
public:
    int topdown(vector<int>&prices ,int i , int buy, int cap ,
                vector<vector<vector<int>>> &dp)
    {
        if(cap ==0 or i == prices.size() ) return 0 ; 
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap] ; 
        if(buy)
        {
            int take = -prices[i] + topdown(prices,i+1,0,cap ,dp);
            int notTake = topdown(prices,i+1,1,cap,dp);
            dp[i][buy][cap] = max(take ,notTake );
        }
        else
        {
            int take = prices[i] + topdown(prices,i+1,1,cap-1,dp);
            int notTake = topdown(prices, i+1, 0 ,cap,dp);
            dp[i][buy][cap] = max(take ,notTake );
        }
        return dp[i][buy][cap];
    }
    int maxProfit(int k, vector<int>& prices) {
        int cap =  k , n = prices.size() ;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(cap+1,-1))) ;
        return topdown( prices , 0 ,1 , cap ,dp );
    }
};