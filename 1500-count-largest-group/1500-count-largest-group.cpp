class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        int ans=0, c=0;
        for (int i=1; i<=n; i++)
        {
            int t=i, sum=0;
            while (t>0)
            {
                sum+=t%10;
                t/=10;
            }
            m[sum]++;
            ans=max(ans, m[sum]);
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==ans) c++;
        }
        return c;
    }
};