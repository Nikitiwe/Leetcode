class Solution {
public:
    int leastBricks(vector<vector<int>>& w) {
        long s = 0;
        for (int j=0; j!=w[0].size(); j++) s += (long)w[0][j];
        unordered_map<long, long> arr;
        for (int i=0; i!=w.size(); i++)
        {
            long t = 0;
            for (int j=0; j!=w[i].size(); j++)
            {
                t += (long)w[i][j];
                arr[t]++;
            }
        }
        long ans = 0;
        for (auto i=arr.begin(); i!=arr.end(); i++)
        {
            if (i->first != 0 && i->first != s) ans = max(ans, i->second);
        }
        return w.size() - ans;
    }
};