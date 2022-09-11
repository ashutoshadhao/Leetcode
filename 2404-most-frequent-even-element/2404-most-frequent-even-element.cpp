class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp ;
        int ans = 0 ,ele = 0 , odd = 0 ;
        for(auto it : nums )
        {
            if(it % 2 == 0 )
            {
                mp[it]++ ;
                if( ans < mp[it])
                {
                    ans = max(ans,mp[it] ) ;
                    ele = it ;
                }
                else if(ans == mp[it] and ele > it )
                {
                    ele = it ;
                }
            }
            else 
                odd++ ;
        }
        if(odd == nums.size() ) return -1 ;
        
      return ele ;
    }
};