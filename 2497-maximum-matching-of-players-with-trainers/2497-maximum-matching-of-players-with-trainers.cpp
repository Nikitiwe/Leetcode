class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort (players.begin(), players.end());
        sort (trainers.begin(), trainers.end());
        int ans=0, t=trainers.size()-1, p=players.size()-1;
        while (t>=0&&p>=0)
        {
            if (players[p]<=trainers[t])
            {
                ans++;
                p--;
                t--;
            }
            else p--;
        }
        return ans;
    }
};