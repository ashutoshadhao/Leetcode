class Solution
{
    public:
        int bagOfTokensScore(vector<int> &tokens, int power) {
            int score = 0 , n = tokens.size() , maxScore = 0  ;
            sort(tokens.begin() ,tokens.end()) ;
            int left = 0 , right =  n -1 ;
            while( left <= right )
            {
                if(tokens[left] <= power )
                {
                    power = power - tokens[left];
                    score++;
                    maxScore = max(score,maxScore);
                    left++;
                }
                else if( score != 0 )
                {
                    power = power + tokens[right] ;
                    right--;
                    score--;
                }
                else
                {
                    break;
                }
            }
            return maxScore; 
        }
};