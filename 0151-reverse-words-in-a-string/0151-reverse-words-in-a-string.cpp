class Solution
{
    public:
        string reverseWords(string s)
        {
            stack<string> st;
            bool flag = false;
            string temp;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ' '
                    and flag == false) continue;
                flag = true;
                if (s[i] == ' ')
                {
                    // cout << "'" << temp << "'" << endl;
                    if (!temp.empty())
                    {
                        st.push(temp);
                    }

                    temp = "";
                    continue;
                }
                temp.push_back(s[i]);
            }
            if (!temp.empty())
            {
                st.push(temp);
            }
           	// cout<<"'"<<temp<<"'"<<endl;
            string ans = "";
            while (!st.empty())
            {
                ans = ans + st.top() + " ";
                st.pop();
            }
            ans.pop_back();
            return ans;
        }
};