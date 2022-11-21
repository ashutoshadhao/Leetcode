class Solution {
public:
    bool check_for_exit( int r ,int c, int n , int m )
    {
        if( r == 0 or c == 0 or r == n-1 or c == m-1 )
            return true ;
        return false ;
    }
    bool check_for_valid( int r ,int c, int n , int m )
    {
        if( r >= 0 and c >= 0 and r < n  and c < m)
            return true; 
        return false ;
    }
     int bfs(vector<vector<char>>& maze, vector<int>& entrance) {
         
         int x = entrance[0] , y = entrance[1] ;
         vector<int> disx = { -1 ,1 ,0 , 0 };
         vector<int> disy = {0,0,-1,1};
         
         int n = maze.size() , m =maze[0].size() ;
         vector<vector<int>> distance(n,vector<int>(m,-1));
         distance[x][y] = 0 ; 
         queue<pair<int,int>> q ;
         q.push({x,y});
         
         while(!q.empty())
         {
             auto it = q.front() ;
             int r = it.first ;
             int c = it.second ;
             q.pop() ;
             
             if(distance[r][c] != 0 )
             {
                 if(check_for_exit(r,c,n,m) )
                     return distance[r][c];
             }
             
             for(int i = 0 ; i < disx.size() ; i++)
             {
                 int nrow = r + disx[i] ;
                 int ncol = c + disy[i] ;
                 
                 if( check_for_valid(nrow,ncol,n,m) and maze[nrow][ncol] == '.' and distance[nrow][ncol] == -1  )
                 {
                     q.push({nrow,ncol}) ; 
                     distance[nrow][ncol] =  distance[r][c] + 1 ; 
                 }
             }
         }
         return -1 ;
     }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return bfs(maze,entrance) ;
    }
};