class Solution
{
    public:
        bool dfs(string s, int i, int j, vector<vector < char>> &board)
        {
            if (s.size() == 0) return true;
            if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size())
                return false;
            if (s[0] != board[i][j]) return false;
            char ch = board[i][j];

            board[i][j] = '$';
            bool up = dfs(s.substr(1), i - 1, j, board);
            board[i][j] = ch;

            board[i][j] = '$';
            bool down = dfs(s.substr(1), i + 1, j, board);
            board[i][j] = ch;

            board[i][j] = '$';
            bool right = dfs(s.substr(1), i, j + 1, board);
            board[i][j] = ch;

            board[i][j] = '$';
            bool left = dfs(s.substr(1), i, j - 1, board);
            board[i][j] = ch;

            return (up or down or right or left);
        }
    bool exist(vector<vector < char>> &board, string word)
    {
       
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if( board[i][j] == word[0]  )
                {
                    if( dfs(word, i,j,board)) return true; 
                }
            }
        }
       return false ;
    }
};