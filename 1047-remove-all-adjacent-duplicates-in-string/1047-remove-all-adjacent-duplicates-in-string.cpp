class Solution
{
    public:
        string removeDuplicates(string s)
        {
            stack<char> st;
            for (int i = 0; i < s.size(); i++)
            {
                bool flag = false ;
                while (!st.empty() and s[i] == st.top())
                {
                    flag = true ;
                    st.pop();
                }
                if(flag == false )
                     st.push(s[i]);
            }
            string ans;
            while (!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};