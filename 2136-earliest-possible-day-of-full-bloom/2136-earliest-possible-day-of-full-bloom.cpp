class Solution {
public:
    static bool comp( pair<int,int> &a, pair<int,int> &b )
    {
        return a.second > b.second ;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
            vector<pair<int,int>> vec ;
        int n = plantTime.size() ; 
        for(int i = 0 ; i < n ; i++ )
        {
            vec.push_back({plantTime[i],growTime[i]}) ;
        }
        sort(vec.begin(),vec.end(),comp); 
        int ans = 0 ;
        int start = 0 ;
        for( int i =0 ; i< n ; i++ )
        {
            start += vec[i].first ;
            ans = max(ans,start + vec[i].second ) ;
        }
        return ans; 
    }
};