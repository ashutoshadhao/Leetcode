class Solution {
public:
    void dfs(vector<vector<int>>& image, int row ,int col, int color,  vector<vector<int>> &ans ,
             vector<int>& deltaRow , vector<int> &deltaCol , int iniColor)
    {
        ans[row][col] = color ;
        int n = image.size() ;
        int m = image[0].size();
        for(int i = 0 ; i < 4 ; i++ )
        {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if( nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and image[nrow][ncol] == iniColor and
               ans[nrow][ncol] != color )
                dfs(image,nrow,ncol,color,ans,deltaRow,deltaCol,iniColor);
               
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image ;
        vector<int> deltaRow = {-1,0,0,1};
        vector<int> deltaCol = {0,-1,1,0};
        dfs(image,sr,sc,color,ans,deltaRow,deltaCol,iniColor);
        return ans;
    }
};