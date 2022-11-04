class Solution
{
    public:
        bool isPalindrome(string s)
        {
            int i = 0, j = s.size() - 1;
            while (i < j)
            {
                char a = tolower(s[i]);
                char b = tolower(s[j]);

                if (a == ' '
                    or((a<'a'
                        or a > 'z') and(a < '0' or a > '9')))
                {
                    i++;
                    continue;
                }
                if (b == ' '
                    or((b<'a'
                        or b > 'z') and(b < '0' or b > '9')))
                {
                    j--;
                    continue;
                }
               	// cout << a << "  " << b << endl;
                if (a != b)
                {
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
};