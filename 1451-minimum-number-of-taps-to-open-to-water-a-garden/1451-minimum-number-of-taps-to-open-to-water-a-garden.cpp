class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int l=0, r=0, ans=0;
        while (r<n)
        {
            for (int i=0; i!=ranges.size(); i++)
            {
                if (i-ranges[i]<=l) r=max(r, i+ranges[i]);
            }
            if (l==r) return -1;
            ans++;
            l=r;
        }
        return ans;
    }
};