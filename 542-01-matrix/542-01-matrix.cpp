class Solution
{
    public:
        vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
        {
            int n = mat.size(), m = mat[0].size();
            vector<vector < int>> dis(n, vector<int> (m, 0));
            vector<vector < int>> vis(n, vector<int> (m, 0));
            queue<vector < int>> q;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mat[i][j] == 0)
                    {
                        vis[i][j] = 1;
                        q.push({ i,j,0 });
                    }
                }
            }
            
            while(!q.empty())
            {
                vector<int> node  = q.front() ;
                int row = node[0] ;
                int col = node[1] ;
                int distance = node[2] ;
                q.pop() ;
                int DR[4] = {1, 0, -1, 0};
                int DC[4] = {0, -1, 0, 1};
                for (int delta = 0; delta < 4; delta++)
                {
                    int nrow = row + DR[delta];
                    int ncol = col + DC[delta];
                    if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m 
                          and vis[nrow][ncol] == 0 )
                    {
                        vis[nrow][ncol] = 1;
                        dis[nrow][ncol] = distance + 1 ;
                        q.push({nrow, ncol , distance+1});
                    }
                }
                
            }
            return dis; 
        }
};