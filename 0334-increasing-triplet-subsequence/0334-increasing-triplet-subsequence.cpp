class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int one = INT_MAX , two = INT_MAX ;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            if(one > nums[i])
            {
                one = nums[i] ;
            }
            else if( one < nums[i] and two > nums[i] )
            {
                two = nums[i] ;
            }
            else if( two < nums[i] )
                return true; 
        }
        return false ;
            
    }
};