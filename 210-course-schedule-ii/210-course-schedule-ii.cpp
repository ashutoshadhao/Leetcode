class Solution
{
    public:
        vector<int> findOrder(int numCourses, vector<vector < int>> &prerequisites)
        {
            int V = numCourses;
            vector<int> adj[V];
            for (int i = 0; i < prerequisites.size(); i++)
            {
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
            vector<int> indegree(V, 0);
            for (int i = 0; i < V; i++)
            {
                for (auto it: adj[i])
                {
                    indegree[it]++;
                }
            }
            queue<int> q;
            vector<int> ans;
            for (int i = 0; i < V; i++)
            {
                if (indegree[i] == 0)
                    q.push(i);
            }
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto it: adj[node])
                {
                    indegree[it]--;
                    if (indegree[it] == 0)
                        q.push(it);
                }
            }
            if(ans.size() == V )
                return ans;
            return {};
        }
};