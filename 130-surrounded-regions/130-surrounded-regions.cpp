class Solution
{
    public:
        void solve(vector<vector < char>> &board)
        {
            int n = board.size(), m = board[0].size();
            vector<vector < int>> vis(n, vector<int> (m, 0));
            queue<pair<int, int>> q;
            for (int i = 0; i < n; i++)
            {
                if (board[i][0] == 'O')
                {
                    vis[i][0] = 1;
                    q.push({ i, 0 });
                }
            }
            for (int i = 0; i < m; i++)
            {
                if (board[0][i] == 'O')
                {
                    vis[0][i] = 1;
                    q.push({ 0,
                        i });
                }
            }
            for (int i = 0; i < m; i++)
            {
                if (board[n - 1][i] == 'O')
                {
                    vis[n - 1][i] = 1;
                    q.push({ n - 1,i });
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (board[i][m - 1] == 'O')
                {
                    vis[i][m - 1] = 1;
                    q.push({ i, m - 1 });
                }
            }
            
            while( !q.empty() )
            {
                int row = q.front().first ;
                int col = q.front() .second ;
                q.pop() ;
                int DR[4] = {1, 0, -1, 0};
                int DC[4] = {0, -1, 0, 1};
                for (int delta = 0; delta < 4; delta++)
                {
                    int nrow = row + DR[delta];
                    int ncol = col + DC[delta];
                    if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m 
                          and vis[nrow][ncol] == 0 and board[nrow][ncol] == 'O')
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
                
            }
            for(int i = 0 ; i < n ; i++ )
            {
                for( int j = 0 ; j < m ; j++ )
                {
                    if(vis[i][j] == 0 )
                    {
                        board[i][j] = 'X' ;
                    }
                }
            }
            
        }
};