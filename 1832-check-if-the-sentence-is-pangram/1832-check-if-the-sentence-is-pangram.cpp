class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> mp(26,0) ;
        for( auto it : sentence)
            mp[it-'a']++;
        for(auto it : mp )
            if(it == 0 ) return false ;
        return true; 
    }
};