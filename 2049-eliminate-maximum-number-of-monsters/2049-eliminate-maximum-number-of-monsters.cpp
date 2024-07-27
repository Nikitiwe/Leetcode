class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time(dist.size(), 0);
        for (int i=0; i!=time.size(); i++)
        {
            time[i]=(dist[i]+speed[i]-1)/speed[i];
        }
        sort(time.begin(), time.end());
        int ans=1;
        for (int i=1; i<time.size(); i++)
        {
            if (time[i]<=i) break;
            else ans++;
        }
        return ans;
    }
};