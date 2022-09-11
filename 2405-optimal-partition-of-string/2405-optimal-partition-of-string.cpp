class Solution {
public:
    int partitionString(string s) {
        int ans = 0 ; 
        vector<int> mp(26,0);
        for(int i = 0 ; i < s.size() ; i++ )
        {
            mp[s[i]-'a']++ ;
            if(mp[s[i]-'a'] > 1 ) 
            {
                // cout<<i+1<<"   "; 
                vector<int> mp2(26,0);
                mp= mp2 ;
                mp[s[i]-'a']++ ;
                ans++;
            }
        }
        cout<<endl; 
        return ans+1 ;
    }
};