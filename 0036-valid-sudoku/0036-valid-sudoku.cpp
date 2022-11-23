class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            unordered_map<string, int> mp;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] != '.')
                    {
                        if (mp.find("row" + to_string(i) + board[i][j]) != mp.end())
                            return false;
                        if (mp.find("col" + to_string(j) + board[i][j]) != mp.end())
                            return false;
                        if (mp.find("box" + to_string((i / 3) *3 + j / 3) + board[i][j]) != mp.end())
                            return false;
                        mp["row" + to_string(i) + board[i][j]]++ ; 
                        mp["col" + to_string(j) + board[i][j]]++ ; 
                        mp["box" + to_string((i / 3) *3 + j / 3) + board[i][j]]++ ; 
                    }
                }
            }
            return true;
        }
};