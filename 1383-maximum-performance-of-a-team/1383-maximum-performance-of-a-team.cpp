class Solution
{
    static bool comp(pair<int, int> &a , pair<int, int> &b)
    {
        return a.second > b.second ;
    }
    public:
    int MOD = 1e9+ 7 ;
        int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
        {
            vector<pair<int, int>> engineers;
            
            for (int i = 0; i < n; i++)
                engineers.push_back({ speed[i] , efficiency[i]});
            
            sort(engineers.begin(), engineers.end() ,comp);
            
             priority_queue <int, vector<int>, greater<int> > pq;
            // for(auto it : engineers) cout<< it.first<<"  "<<it.second<<endl;
            long maxPerformance = 0 ; 
            long totalSpeed = 0 ; 
            
            for (int i = 0; i < n; i++) {
                long currEff = engineers[i].second ;
                long currSpeed = engineers[i].first ;
                if(pq.size() == k )
                {
                    totalSpeed = totalSpeed - pq.top() ;
                    pq.pop() ;
                }
                pq.push(currSpeed);
                totalSpeed += currSpeed ; 
                long  performance = totalSpeed * (long)currEff  ;
                maxPerformance = max(maxPerformance,performance);
                
            }
            return maxPerformance % MOD  ;
        }
};