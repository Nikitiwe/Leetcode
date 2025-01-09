class Solution {
public:
    int countBalls(int l, int h) {
        int ans=0;
        unordered_map<int, int> m;
        for (int i=l; i<=h; i++)
        {
            int t=i, s=0;
            while (t>0)
            {
                s+=t%10;
                t/=10;
            }
            m[s]++;
            ans=max(ans, m[s]);
        }
        return ans;
    }
};