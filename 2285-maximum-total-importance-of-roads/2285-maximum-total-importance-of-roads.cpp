class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        for(auto it : roads)
        {
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        sort(indegree.begin(),indegree.end(),greater<int>());
        long long ans = 0 ;
        int len =  n ;
        for(auto it : indegree )
        {
            ans += ( 1LL*it * len ) ;
            len--;
        }
        return ans; 
    }
};