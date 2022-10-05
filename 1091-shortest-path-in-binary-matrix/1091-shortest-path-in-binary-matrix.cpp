class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size() ;
        
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        queue<vector<int>> q ;
        
        if(grid[0][0] == 0 )
            q.push({0,0,0}) ;
        
        distance[0][0] = 0 ;
        int DR[] = {1, 0, -1, 0, -1, 1, 1, -1};
        int DC[] = {0, -1, 0, 1, -1, 1, -1, 1};
        while(!q.empty())
        {
            vector<int> vec = q.front() ;
            int row = vec[0];
            int col = vec[1] ;
            int dis = vec[2] ;
            q.pop() ;
            if( row == n-1 and col == m-1 ) 
                return dis +1 ; 
           
            for(int i = 0 ; i < 8 ; i++ )
            {
                int nrow = row + DR[i];
                int ncol = col + DC[i];
                
                if( nrow >= 0 and nrow < n and ncol >= 0 and ncol < m 
                   and grid[nrow][ncol] == 0 and dis + 1 < distance[nrow][ncol] )
                {
                    distance[nrow][ncol] = dis + 1 ;
                    
                    q.push({nrow,ncol,distance[nrow][ncol]}) ;
                }
            }
 
        }
        return -1 ; 
    }
};