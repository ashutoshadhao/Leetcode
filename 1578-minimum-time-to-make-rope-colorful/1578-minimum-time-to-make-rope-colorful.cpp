class Solution
{
    public:
        int minCost(string colors, vector<int> &neededTime)
        {
            int sum = 0;
            int n = neededTime.size();
            char prevChar = colors[0];
            int prevCount = 1;
            int prevMaximum = neededTime[0];
            int totalPrevSum = neededTime[0];
            for (int i = 1; i < n; i++)
            {
                if (colors[i] != prevChar)
                {
                    if (prevCount > 1)
                    {
                        sum += (totalPrevSum - prevMaximum);
                    }
                    prevCount = 1;
                    prevChar = colors[i];
                    prevMaximum = neededTime[i];
                    totalPrevSum = neededTime[i];
                }
                else {
                    totalPrevSum += neededTime[i] ;
                    prevMaximum = max( prevMaximum ,neededTime[i]) ;
                    prevCount++ ; 
                }
            }
            if (prevCount > 1)
            {
                sum += (totalPrevSum - prevMaximum);
            }
            return sum;
        }
};