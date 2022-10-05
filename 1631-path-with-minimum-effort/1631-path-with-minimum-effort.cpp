class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         int n = heights.size() , m = heights[0].size() ;
        
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq ;
        pq.push({0,0,0}) ;
        
        distance[0][0] = 0 ;
        int DR[4] = {1, 0, -1, 0};
        int DC[4] = {0, -1, 0, 1};
        
        while(!pq.empty())
        {
            vector<int> vec = pq.top() ;
            int row = vec[1];
            int col = vec[2] ;
            int dis = vec[0] ;
            pq.pop() ;
        
            for(int i = 0 ; i < 4 ; i++ )
            {
                int nrow = row + DR[i];
                int ncol = col + DC[i];
                
                if( nrow >= 0 and nrow < n and ncol >= 0 and ncol < m 
                    and max(abs(heights[row][col] - heights[nrow][ncol]) , dis) < distance[nrow][ncol] )
                {
                    distance[nrow][ncol] = max(abs(heights[row][col] - heights[nrow][ncol]) , dis);
                    pq.push({distance[nrow][ncol],nrow,ncol}) ;
                }
            }
 
        }
        return distance[n-1][m-1] ; 
    }
};