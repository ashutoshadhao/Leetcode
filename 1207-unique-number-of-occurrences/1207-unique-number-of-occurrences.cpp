class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp , mp2 ;
        for(auto it : arr ) mp[it]++ ;
        for(auto it : mp )
        {
            if(mp2[it.second] != 0 )
                return false ;
            mp2[it.second]++ ;
        }
        return true; 
    }
};