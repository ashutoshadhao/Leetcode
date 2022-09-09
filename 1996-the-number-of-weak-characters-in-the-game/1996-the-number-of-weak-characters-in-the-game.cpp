class Solution {
public:
    static bool comp( vector<int> &a ,vector<int> &b )
    {
        if( a[0] == b[0] ) return a[1] > b[1];
        else 
            return b[0] > a[0] ;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        int maxi = INT_MIN , cnt = 0  , n = properties.size() ;
        for(int i = n-1 ; i >= 0   ; i-- ) 
        {
            // cout<<properties[i][0] <<"   "<<properties[i][1]<<endl;
            if( maxi >  properties[i][1] ) cnt++;
            if( maxi  <  properties[i][1])
                maxi = properties[i][1] ;
            
        }
        return cnt ; 
    }
};