class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX)) ;
        for(int i = 0 ; i < edges.size() ; i++ )
        {
            dist[edges[i][1]][edges[i][0]] = edges[i][2] ;
            dist[edges[i][0]][edges[i][1]] = edges[i][2] ; 
        }
          for(int i = 0 ; i < n ; i++ )
            dist[i][i] = 0 ;
        
        for(int k = 0 ; k < n ; k++ )
        {
            for( int i = 0 ; i < n ; i++ )
            {
                for( int j = 0 ; j < n ; j++ )
                {
                    if(dist[i][k] == INT_MAX or dist[k][j] == INT_MAX ) 
                        continue ; 
                    dist[i][j] = min(dist[i][k] + dist[k][j] , dist[i][j] ) ;
                }
            }
        }
        
        int cityNo = -1 ;
        int minCity = n ;
        for( int city = 0 ; city < n ; city++ )
        {
            int cnt = 0 ;
            for( int adjcity = 0 ; adjcity < n ; adjcity++ )
            {
                if( dist[city][adjcity] <= distanceThreshold )
                    cnt++ ;
            }
            if( cnt <= minCity )
            {
                minCity = cnt ; 
                cityNo = city ;
            }
        }
        return cityNo ;
    }
};