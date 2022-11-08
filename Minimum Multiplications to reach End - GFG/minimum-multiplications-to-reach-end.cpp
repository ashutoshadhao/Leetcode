//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q ;
        q.push({0,start}) ;
        int MOD = 100000  ;
        vector<int> dis(MOD,1e9);
        dis[start] = 0 ;
        while(!q.empty())
        {
            int  step = q.front().first ;
            int node = q.front().second ;
            q.pop();
            for( auto it : arr )
            {
                int num = (it * node ) % MOD ;
               
                if(step + 1 < dis[num])
                {
                    dis[num] = step + 1 ;
                     if(num == end ) return step+1;
                     q.push({step+1 , num });
                }
                    
            }
        }
        return -1 ;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends