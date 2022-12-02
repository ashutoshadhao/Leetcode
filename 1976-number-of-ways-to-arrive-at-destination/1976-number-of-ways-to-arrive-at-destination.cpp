#define ll long long int 
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll mod = 1e9 + 7 ; 
        vector<pair<ll,ll>> adj[n] ;
        for(int i = 0 ; i < roads.size() ; i++ )
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]}) ;
             adj[roads[i][1]].push_back({roads[i][0],roads[i][2]}) ;
        }
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq ;
        vector<ll> dist(n,LONG_MAX) , ways(n,0) ;
        pq.push({0,0}) ;
        dist[0]= 0 ; 
        ways[0] = 1 ;
        while(!pq.empty())
        {
            ll wt = pq.top().first ;
            ll node = pq.top().second ;
            pq.pop() ;
            for( auto it : adj[node]) 
            {
                ll xnode = it.first ;
                ll xwt = it.second ;
                if( (xwt + wt) < dist[xnode])
                {
                   
                    dist[xnode] = xwt + wt ;
                     pq.push({xwt + wt , xnode }) ;
                    ways[xnode] = ways[node] ;
                }
                else if ( (xwt + wt) == dist[xnode]) 
                {
                    ways[xnode] =( ways[node] + ways[xnode]) % mod ; 
                }
            }
        }
        return ways[n-1] % mod ;
    }
};