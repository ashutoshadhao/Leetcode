class Solution
{
    public:
        void dfs(vector<vector < int>> &heights, vector< vector< int>> &ocean, int i, int j, int prev)
        {
            if (i < 0 or i >= heights.size() or j < 0 or j >= heights[0].size())
                return;
            if (ocean[i][j] == 1) return;
            if (prev > heights[i][j]) return;
            ocean[i][j] = 1;

            dfs(heights, ocean, i + 1, j, heights[i][j]);
            dfs(heights, ocean, i, j + 1, heights[i][j]);
            dfs(heights, ocean, i - 1, j, heights[i][j]);
            dfs(heights, ocean, i, j - 1, heights[i][j]);
        }
    vector<vector < int>> pacificAtlantic(vector<vector < int>> &heights)
    {
        vector<vector < int>> ans;
        int n = heights.size(), m = heights[0].size();
       	if(n < 1 ) return ans ;
        vector<vector < int>> pacific(n, vector<int> (m, 0));
        vector<vector < int>> atlantic(n, vector<int> (m, 0));
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, 0, i, -1);
            dfs(heights, atlantic, n - 1, i, -1);
        }
        for (int i = 0; i < n ; i++)
        {
            dfs(heights, pacific, i, 0, -1);
            dfs(heights, atlantic, i, m-1, -1);
        }
        for(int i = 0 ; i < n; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if(pacific[i][j] == 1 and  atlantic[i][j] == 1  )
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};