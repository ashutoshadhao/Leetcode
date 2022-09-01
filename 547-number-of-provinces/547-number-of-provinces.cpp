class Solution
{
    public:
        void dfs(vector<int> &vis, vector<int> adj[], int node)
        {
            vis[node] = 1;
            for (auto it: adj[node])
            {
                if (vis[it] == 0)
                {
                    dfs(vis, adj, it);
                }
            }
        }
    int findCircleNum(vector<vector < int>> &isConnected)
    {
        int v = isConnected.size();
        vector<int> adj[v];
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1 and i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(v, 0);
        int cnt = 0;
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                cnt++;
                dfs(vis, adj, i);
            }
        }
        return cnt;
    }
};