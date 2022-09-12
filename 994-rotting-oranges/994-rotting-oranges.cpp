class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , freshcnt = 0 ; 
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<vector<int>> q; 
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if(grid[i][j] == 2 )
                {
                    vis[i][j] = 2 ;
                    q.push({i,j,0});
                }
                if(grid[i][j] == 1 ) freshcnt++ ; 
            }
        }
        int totalTime = 0 ;
        int deltaRow[] = {-1,0,+1,0};
        int deltaCol[] = {0,1,0,-1};
        int cnt = 0 ; 
        while(!q.empty())
        {
            auto vec = q.front() ; 
            q.pop() ;
            int row = vec[0];
            int col = vec[1] ;
            int time = vec[2];
            totalTime = max(totalTime , time );
            for(int i = 0 ; i < 4 ; i++ )
            {
                int nrow = row + deltaRow[i] ;
                int ncol = col + deltaCol[i] ;
                if( nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and vis[nrow][ncol] != 2 and 
                  grid[nrow][ncol] == 1 )
                {
                    q.push({nrow,ncol,time+1});
                    vis[nrow][ncol] = 2 ;
                    cnt++;
                }
            }
        }
        if(cnt != freshcnt ) return -1 ;
        return totalTime ;
       
    }
};