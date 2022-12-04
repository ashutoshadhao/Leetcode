class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size() ; 
        vector<long long int > prefix(n,0) , suffix(n,0) ;
        long long int  sum = 0 ; 
        for( int i =0 ; i < n ; i++ )
        {
            sum += nums[i] ; 
            prefix[i] = sum ;
        }
        sum = 0 ; 
        for( int i = n - 1 ; i >=0 ; i-- )
        {
            sum+= nums[i] ; 
            suffix[i] = sum ;
        }
        suffix.push_back(0) ; 
        long long int  i = 0 , j = 1 ;
        long long int  index = 0 , mini = INT_MAX ; 
        while( i < n )
        {
            long long int  val ; 
            if( suffix[j] == 0 )
            {
                val = abs( prefix[i] /(i+1)) ;
            }
            else 
             val = abs( prefix[i] /(i+1) - suffix[j] / (n - j )) ; 
            // cout<< prefix[i] /(i+1) << "    " << suffix[j] / (n - j ) << "    "<<val<<endl;
            if( val < mini )
            {
                mini = val ;
                index = i ; 
            }
            i++ ;
            j++ ; 
        }
        return index ;
    }
};