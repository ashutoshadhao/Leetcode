class Solution
{
    public:
        int reverse(int x)
        {
            string s = to_string(x);
            int flag = 1;
            if (s[0] == '-')
            {
                flag = -1;
                s = s.substr(1);
            }
            int n = s.size();
            long long int ans = 0 ;
            for( int i = n-1 ; i >=0  ; i-- )
            {
                if( ans > INT_MAX ) return 0 ;
                ans += (s[i] - '0') * pow(10,i) ;
                // cout<<ans<<endl;
            }
            return flag * ans ;
        }
};