class Solution
{
    public:
        string reverse(string s)
        {
            int i = 0, j = s.size() - 1;
            while (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            return s;
        }
    bool sumOfNumberAndReverse(int num)
    {
        int val = 0;
        while (val <= num)
        {
            int b = val ;
            string temp = reverse(to_string(val));
            val = b ;
            int a = stoi(temp);
            if (val + a == num) return true;
            val++;
        }
        return false;
    }
};