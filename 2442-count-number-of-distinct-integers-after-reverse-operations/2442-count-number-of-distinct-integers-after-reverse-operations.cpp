class Solution {
public:
    string reverse( string s )
    {
        int i = 0 , j = s.size() - 1 ;
        while( i < j )
        {
            swap(s[i],s[j]) ;
            i++ ;
            j--;
        }
        return s ;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size() ; 
        set<int> st(nums.begin(),nums.end()) ;
        for( int i = 0 ; i < n ; i++ )
        {
            string temp = to_string(nums[i]);
            temp = reverse(temp);
            st.insert(stoi(temp));
        }
        return st.size() ;
    }
};