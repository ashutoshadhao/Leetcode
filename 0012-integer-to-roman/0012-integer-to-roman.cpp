class Solution
{
    public:
        string intToRoman(int num)
        {
            unordered_map<int, char> mp;
            mp[1] = 'I', mp[5] = 'V', mp[1000] = 'M', mp[500] = 'D', mp[100] = 'C';
            mp[10] = 'X', mp[50] = 'L';
            vector<int> vec = {1000, 500, 100, 50, 10, 5, 1};
            int index = 0;
            string ans ;
            while (num)
            {
                if (num == 9)
                {
                    ans.push_back('I');
                    ans.push_back('X');
                    num = num - 9 ;
                }
                else if (num == 4)
                {
                    ans.push_back('I');
                    ans.push_back('V');
                    num = num - 4 ;
                }
                else if (num >= 40 and num < 50 )
                {
                    ans.push_back('X');
                    ans.push_back('L');
                    num = num - 40 ;
                }
                else if (num >= 400 and num < 500 )
                {
                    ans.push_back('C');
                    ans.push_back('D');
                    num = num - 400 ;
                }
                else if (num >= 90 and num < 100 )
                {
                    ans.push_back('X');
                    ans.push_back('C');
                    num = num - 90 ;
                }
                else if (num >= 900 and num < 1000 )
                {
                    ans.push_back('C');
                    ans.push_back('M');
                    num = num - 900 ;
                }
                else if (num >= vec[index])
                {
                    int times = num / vec[index];
                    num = num - times *vec[index];
                    while (times--)
                        ans.push_back(mp[vec[index]]);
                }
                index++;
            }
            return ans; 
        }
};