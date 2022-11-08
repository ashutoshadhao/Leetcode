class Solution
{
    public:
        string makeGood(string s)
        {
            stack<char> st;

            string ans;
            for (int i = 0; i < s.size(); i++)
            {
                st.push(s[i]);
                if (st.size() > 1)
                {
                    char one = st.top();
                    st.pop();
                    char two = st.top();
                    st.pop();
                    cout << one << "  " << two << endl;
                    if ((one >= 'a'
                            and one <= 'z') and(two >= 'A'
                            and two <= 'Z') and tolower(one) == tolower(two) )
                    {
                        if (ans.size())
                            ans.pop_back();
                        continue;
                    }
                    if ((two >= 'a'
                            and two <= 'z') and(one >= 'A'
                            and one <= 'Z')  and tolower(one) == tolower(two) )
                    {
                        if (ans.size())
                            ans.pop_back();
                        continue;
                    }
                    st.push(two);
                    st.push(one);

                    ans.push_back(two);
                }
            }
            if (st.size())
                ans.push_back(st.top());
            return ans;
        }
};