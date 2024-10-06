class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        if (t.size()==1) return d;
        sort(t.begin(), t.end());
        int ans=d;
        for (int i=1; i<t.size(); i++)
        {
            if (t[i]>=t[i-1]+d) ans+=d;
            else ans+=d-(t[i-1]+d-t[i]);
        }
        return ans;
    }
};