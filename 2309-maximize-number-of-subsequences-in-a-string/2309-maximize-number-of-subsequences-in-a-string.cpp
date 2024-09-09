class Solution {
public:
    long long maximumSubsequenceCount(string s, string p) {
        vector<long long> arr(s.size(), 0);
        long long t=0, ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==p[0]) t++;
            arr[i]=t;
        }
        if (p[0]==p[1]) return (t)*(t+1)/2;
        t=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]==p[1])
            {
                ans+=arr[i];
                t++;
            }
        }
        ans+=max(t, arr[s.size()-1]);
        return ans;
    }
};