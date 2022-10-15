class Solution {
public:
    string robotWithString(string s) {
        vector<int> last(26,-1) ;
        for( int i = 0 ; i < s.size() ; i++ ) 
        {
            last[s[i] - 'a'] = i ;
        }
        string ans  ;
        stack<char> st ;
        for( int i = 0 ;i <s.size() ; i++ )
        {
            st.push(s[i]) ;
            while( !st.empty())
            {
                bool exist = true ;
                for( char ch = 'a' ; ch < st.top() ; ch++ )
                {
                    if( i < last[ch-'a'])
                    {
                        exist = false ;
                        break; 
                    }
                }
                if(!exist)
                    break; 
                ans.push_back(st.top()) ;
                st.pop() ;
            }
        }
        return ans; 
    }
};