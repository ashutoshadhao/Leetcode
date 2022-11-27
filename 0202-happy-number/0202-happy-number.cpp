class Solution {
public:
    bool isHappy(int n) {
        
        while(true  )
        {
            long long int ans = 0 ; 
            int temp = n ; 
            while(temp!= 0 )
            {
                int ele = temp % 10  ;
                temp = temp / 10 ; 
                ans  += ele * ele ; 
                
            }
            if ( ans == 1 )
                return true; 
            if(89  == ans  ) 
                return false ; 
            n = ans ;
        }
        return false; 
    }
};