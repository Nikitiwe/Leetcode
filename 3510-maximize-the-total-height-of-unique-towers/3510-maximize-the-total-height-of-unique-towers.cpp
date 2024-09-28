class Solution {
public:
    long long maximumTotalSum(vector<int>& m) {
        sort(m.rbegin(), m.rend());
        int t=m[0];
        long long ans=t;
        t--;
        for (int i=1; i<m.size(); i++)
        {
            t=min(t, m[i]);
            ans+=t;
            if (t<=0) return -1;
            t--;
        }
        return ans;
    }
};