class Solution
{
    public:
        void topdown(int n, vector<string> &ans, string temp, int open, int close)
        {
            if (temp.size() == 2 *n)
            {
                ans.push_back(temp);
                return;
            }
            if (open < n)
            {

                 topdown(n, ans, temp + '(', open + 1, close);
            }
            if (close < open)
            {

                 topdown(n, ans, temp + ')', open, close + 1);
            }
        }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp = "";
        topdown(n, ans, temp, 0, 0);
        return ans;
    }
};