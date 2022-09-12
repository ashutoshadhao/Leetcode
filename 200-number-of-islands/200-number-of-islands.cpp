class Solution {
public:
    void bfs(int row, int col ,vector<vector<char>> &grid ,vector<vector<int>> &vis )
    {
        vis[row][col] = 1 ;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size() ;
        int m = grid[0].size() ;
        int DR[4]={1, 0, -1, 0};
        int DC[4]={0, -1, 0, 1};
        while(!q.empty())
        {
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;
            
            for( int delta = 0 ; delta < 4 ; delta++ )
            {
              
                int nrow = row + DR[delta] ;
                int ncol = col + DC[delta] ;
                if( nrow >= 0 and nrow < n and ncol >= 0 and ncol < m 
                   and grid[nrow][ncol] == '1' and vis[nrow][ncol] == 0 )
                {
                    vis[nrow][ncol] = 1 ;
                    q.push({nrow,ncol});
                }
                    
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m =grid[0].size() ;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j =0 ; j < m ; j++)
            {
                if(!vis[i][j] and grid[i][j] == '1' )
                {
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt ;
    }
};