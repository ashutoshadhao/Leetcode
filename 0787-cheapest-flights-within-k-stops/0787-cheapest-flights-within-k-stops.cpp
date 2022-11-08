class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {
            vector<pair<int, int>> vec[n];
            for (auto it: flights)
            {
                vec[it[0]].push_back({ it[1], it[2] });
            }
            vector<int> dis(n, 1e9);
            queue<pair<int, pair<int, int>>>q;
            q.push({ 0,
                {
                    src,
                    0
                } });
            dis[src] = 0;
            while (!q.empty())
            {
                auto it = q.front();
                q.pop();
                int stops = it.first;
                int node = it.second.first;
                int cost = it.second.second;

                if (stops > k) continue;
                for (auto it: vec[node])
                {
                    int adjNode = it.first;
                    int edw = it.second;
                    if (cost + edw < dis[adjNode] and stops <= k)
                    {
                        dis[adjNode] = cost + edw;
                        q.push({stops + 1 , { adjNode, cost + edw }}) ;
                    }
                }
            }
            if(dis[dst] == 1e9 )
                return -1 ;
            return dis[dst]; 
        }
};