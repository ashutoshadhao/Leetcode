class Solution {
public:
    bool isUgly(int n) {
        if( n < 1 ) return false ;
        vector< int > primes = { 2 , 3 ,5 } ; 
        for( auto it : primes )
        {
            while( n % it == 0 )
            {
                n = n / it ;
            }
            
        }
        return ( n == 1 ) ; 
        
    }
};