class Solution {
public:
    bool isPalindrome(string &a , int i ,int j )
    {
        while( i <= j ) 
        {
            if(a[i] != a[j]) return false ;
            i++ ;
            j--;
        }
        return true; 
    }
    void topdown( string s , vector<string> & res , vector<vector<string>> &ans, int i )
    {
        if( i == s.size() ) 
        {
            ans.push_back(res);
            return ;
        }
        for(int ind = i ; ind < s.size() ; ind++ )
        {
            if(isPalindrome(s,i,ind))
            {
                res.push_back(s.substr(i,ind - i + 1 ));
                topdown(s,res,ans,ind+1);
                res.pop_back();
            }
        }
            
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> res  ;
        vector<vector<string>> ans; 
        topdown(s, res, ans, 0);
        return ans; 
    }
};