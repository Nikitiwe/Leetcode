class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int ans=0;
        unordered_map<int, int> m;
        for (int i=0; i!=d.size(); i++)
        {
            int a=min(d[i][0], d[i][1]), b=max(d[i][0], d[i][1]);
            ans+=m[10*b+a];
            m[10*b+a]++;
        }
        return ans;
    }
};