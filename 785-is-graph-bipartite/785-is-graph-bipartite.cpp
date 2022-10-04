class Solution
{
    public:
        bool check(vector<vector < int>> &graph, vector< int > &color, int node)
        {
            color[node] = 1;
            queue<int> q;
            q.push(node);
            while (!q.empty())
            {
                int ele = q.front();
                q.pop();
                for (auto it: graph[ele])
                {
                    if (color[it] == -1)
                    {
                        color[it] = !color[ele];
                        q.push(it);
                    }
                    else if (color[it] == color[ele])
                        return false;
                }
            }
            return true;
        }
    bool isBipartite(vector<vector < int>> &graph)
    {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (check(graph, color, i) == false) return false;
            }
        }
        return true;
    }
};