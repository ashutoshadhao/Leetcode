class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        set<vector<int>> st(connections.begin(),connections.end()) ;
        queue<int> q ;
        vector<int> adj[n] ; 
        for( int i = 0 ; i <connections.size() ; i++ )
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        q.push(0);
        vector<int> vis(n,0);
        int cnt = 0 ; 
        while(!q.empty()) 
        {
            int parentNode = q.front() ;
            vis[parentNode] = 1 ;
            q.pop();
            for(auto it : adj[parentNode])
            {
                if( vis[it] == 0 and st.count({parentNode,it}) != 0 )
                {
                    cnt++ ;
                }
                if( vis[it] == 0 ) 
                    q.push(it) ;
            }
        }
        return cnt ;
    }
};