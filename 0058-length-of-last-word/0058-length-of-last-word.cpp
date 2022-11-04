class Solution {
public:
    string str ;
    int lengthOfLastWord(string s) {
        bool flag = true ;
        int cnt = 0 ; 
        
        for(int i = s.size()-1 ; i >= 0  ; i-- )
        {
            if(s[i] == ' ' and flag )
            {
               
                continue ;
            }
            if(s[i] == ' ') break; 
            flag = false ;
            cnt++;  
        }
        return cnt ;
        
    }
};