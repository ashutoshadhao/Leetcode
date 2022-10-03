class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q ;
        int freashOranges = 0 , n = grid.size() , m = grid[0].size() ; 
        vector<vector<int>> vis(n,vector<int>(m , 0 )) ;
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ;  j< m ;j++)
            {
                if( grid[i][j] ==2 )
                {
                    vis[i][j] = 2 ;
                    q.push({i,j,0});
                }
                else if( grid[i][j] )  freashOranges++ ;
                    
            }
        }
        int DR[] = { 0, -1, 0 , 1 } ;
        int DC[] ={-1, 0 , +1 , 0};
        int cnt = 0 ,  maxiTime = 0 ; 
        while(!q.empty())
        {
            vector<int> node = q.front() ;
            int row = node[0] ;
            int col = node[1] ;
            int time = node[2] ;
            q.pop() ;
            maxiTime = max(maxiTime, time ) ;
            for( int i = 0 ; i < 4 ; i++ )
            {
                int nrow = row + DR[i] ; 
                int ncol = col + DC[i] ; 
                if( nrow >= 0 and nrow < n and ncol>=0 and ncol < m 
                   and vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1 )
                {
                    vis[nrow][ncol] = 2 ;
                    q.push({nrow,ncol,time+1}) ; 
                    cnt++ ;
                }
            }
        }
        if( cnt != freashOranges ) return -1 ;
        return maxiTime ;
        
    }
};