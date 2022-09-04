class Solution
{
    public:
        bool isStrictlyPalindromic(int n)
        {
            for (int i = 2; i <= n - 2; i++)
            {
                string s = bitset< 64 >( n << i ).to_string();
                string rev = s;
                reverse(rev.begin(), rev.end());
                // cout << rev << "   " << s << endl;
                if (s != rev) return false;
            }
            return true;
        }
};