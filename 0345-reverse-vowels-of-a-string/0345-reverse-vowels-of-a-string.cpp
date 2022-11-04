class Solution
{
    public:
        string reverseVowels(string s)
        {
            string ch;
            for (auto it: s)
            {
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
                    ch.push_back(it);
            }
            reverse(ch.begin(), ch.end());
            int j = 0;
            for (int i = 0; i < s.size(); i++)
            {
                char it = s[i];
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
                    s[i] = ch[j++];
            }
            return s;
        }
};