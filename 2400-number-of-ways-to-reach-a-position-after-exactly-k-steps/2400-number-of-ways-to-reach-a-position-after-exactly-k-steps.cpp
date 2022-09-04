class Solution
{
    public:
        int dp(int i, int &endPos, int k, vector<vector < int>> &cache)
        {
            if (i == endPos && k == 0)
            {
                return 1;
            }

            if (k <= 0)
            {
                return 0;
            }

            if (cache[i][k] != -1)
            {
                return cache[i][k];
            }

            return cache[i][k] = (dp(i + 1, endPos, k - 1, cache) + dp(i - 1, endPos, k - 1, cache)) % 1000000007;
        }

    int numberOfWays(int startPos, int endPos, int k)
    {
        int diff = abs(endPos - startPos);

       	// conditions for which answer will always be 0
        if (diff > k || (diff % 2 == 1 && k % 2 == 0) || (diff % 2 == 0 && k % 2 == 1))
        {
            return 0;
        }

       	// just shifting start and end positions by same quantity
       	// max value of k can be 1000 so if we have startpos as 0 then (startpos-k) would have been negative so shifting startPos and endPos save us from these cases 
        startPos += 1200;
        endPos += 1200;

        vector<vector < int>> cache(4000, vector<int> (k + 1, -1));
        return dp(startPos, endPos, k, cache);
    }
};