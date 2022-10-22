class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp ;
        unordered_map<char,int> mp2 ;
        for( auto it : t )
            mp[it]++ ;
        int i = 0 ; 
        int j = 0 ; 
        int curr = 0 ;
        int require = t.size() ; 
        string ans ; 
        while(true)
        {
            bool flag1 = false , flag2 = false ;
            while( i < s.size() and curr!=require )
            {
                mp2[s[i]]++ ;
                if(mp2[s[i]] <= mp[s[i]])
                    curr++;
                
                i++;
                flag1 = true; 
            }
            
            while( j < i and curr == require )
            {
                string temp = s.substr(j,i-j);
                // cout<<temp<<endl ;
                if(ans.size() == 0 or temp.size() < ans.size() )
                    ans = temp ;
                mp2[s[j]]-- ;
                if( mp2[s[j]] < mp[s[j]])
                    curr-- ;
                j++;
                flag2 = true; 
            }
            if( flag1 == false or flag2 == false ) break; 
        }
        return ans; 
    }
};