class Solution
{
    public:
        long long cntGoodSubarray(vector<int> &goodNum, int minK, int maxK)
        {
            int n = goodNum.size();
            if( n == 0 ) return 0 ;
            vector<int> minArray(n + 1, n), maxArray(n + 1, n);
            for (int i = n - 1; i >= 0; i--)
            {
                minArray[i] = (goodNum[i] == minK) ? i : minArray[i + 1];
                maxArray[i] = (goodNum[i] == maxK) ? i : maxArray[i + 1];
            }
            long long cnt = 0;
            for (int i = 0; i < n; i++)
            {
                int first_complete_ind = max(minArray[i], maxArray[i]);
                if (first_complete_ind == n) continue;
                cnt += (n - first_complete_ind);
            }
            return cnt;
        }
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        vector<int> goodNum;
        for (auto it: nums)
        {
            if (it < minK or it > maxK)
            {
                ans += cntGoodSubarray(goodNum, minK, maxK);
                goodNum.clear();
                continue;
            }
            goodNum.push_back(it);
        }
        ans += cntGoodSubarray(goodNum, minK, maxK);
        return ans;
    }
};