class Solution {
public:
    bool cycleDetectDFS( vector<vector<int>>& graph ,vector<int> &vis  ,
                         vector<int> & pathVis , vector<int> & check , int node )
    {
        vis[node] = 1 ;
        pathVis[node] = 1 ;
        check[node] = 0 ;
        for( auto it : graph[node] )
        {
            if( vis[it] == 0 )
            {
                if(cycleDetectDFS(graph,vis,pathVis,check,it)) 
                    return true ;
            }
            else if( pathVis[it] == 1)
                return true; 
        }
        check[node] = 1 ;
        pathVis[node] = 0 ;
        return false; 
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size() ;
        vector<int> vis(V,0), pathVis(V,0), check(V,0) ;
        vector<int> safeNodes ;
        for( int i = 0 ; i < V  ; i++)
        {
            if(vis[i] == 0 )
            {
                cycleDetectDFS(graph,vis,pathVis,check,i);
            }
        }
        for( int i = 0 ; i < V ; i++ )
        {
            if(check[i] == 1 ) safeNodes.push_back(i) ;
        }
        return  safeNodes ; 
    }
};