class Solution
{
    public:
        string topdown(int n)
        {
            if (n == 1)
                return "1";
            string say = topdown(n - 1);
            string temp = "";
            int cnt = 1;
            for (int i = 1; i < say.size(); i++)
            {
                if (say[i] == say[i - 1])
                {
                    cnt++;
                }
                else
                {
                    temp += to_string(cnt) + say[i - 1];
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + say[say.size() - 1];

            return temp;
        }
    string countAndSay(int n)
    {
        return topdown(n);
    }
};