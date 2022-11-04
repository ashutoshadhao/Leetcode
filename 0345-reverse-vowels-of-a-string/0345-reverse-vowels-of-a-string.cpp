class Solution
{
    bool check(char ch)
    {
        char it = ch ;
        if (it == 'a'
            or it == 'e'
            or it == 'i'
            or it == 'o'
            or it == 'u'
            or it == 'A'
            or it == 'E'
            or it == 'I'
            or it == 'O'
            or it == 'U')
            return true;
        return false;
    }
    public:
        string reverseVowels(string s)
        {
            string ch;
            int i = 0, j = s.size() - 1;
            while (i < j)
            {
                char a = s[i];
                char b = s[j];
                if (check(a) and check(b))
                    swap(s[i++], s[j--]);
                else if (check(a))
                    j--;
                else if (check(b))
                    i++;
                else
                    i++, j--;
            }
            return s;
        }
};