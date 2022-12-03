class Solution {
public:
    static bool comp(pair<int,char> a, pair<int,char> b )
    {
        return ( a.first > b.first ) ;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp ;
        for(int i = 0 ; i < s.size() ; i++ )
            mp[s[i]]++ ;
        vector<pair<int,char>> vec ;
        for(auto it: mp )
        {
            vec.push_back({it.second,it.first}) ;
        }
        sort(vec.begin(),vec.end(),comp) ;
        string ans = "" ;
        for(auto it : vec )
        {
            while(it.first--)
                ans+= it.second ;
        }
        return ans; 
    }
};