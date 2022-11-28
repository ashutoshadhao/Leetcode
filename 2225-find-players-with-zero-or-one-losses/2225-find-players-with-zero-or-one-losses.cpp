class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> all;
        vector<vector<int>> ans;
        for(auto val :matches)
        {
            all.insert(val[0]);
            all.insert(val[1]);
        }
        unordered_map<int,int> loser;
        for(auto val :matches)
        {
            loser[val[1]]++;
        }
        vector<int> winner , lose;
        for(auto val :all)
        {
            if( loser[val] == 1 )
                lose.push_back(val);
            else if( loser[val] == 0  )
                winner.push_back(val);
        }
        ans.push_back(winner);
        ans.push_back(lose);
        return ans;
    }
};