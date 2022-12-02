class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) 
            return false ;
        vector<int> f1(26,0), f2(26,0) ;
        for( int i = 0 ;i < word1.size() ; i++ )
        {
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }
        for(int i = 0 ; i< word1.size() ; i++ )
        {
           if(f1[word2[i] - 'a'] == 0 )
               return false ;
        }
        sort(f1.begin(),f1.end()) ;
        sort(f2.begin(),f2.end()) ;
        for(int i = 0 ; i < 26 ; i++ )
        {
            // cout<<f1[i]<<"   "<<f2[i]<<"   ";
            if(f1[i] != f2[i]) 
                return false ;
        }
        
        return true; 
    }
};