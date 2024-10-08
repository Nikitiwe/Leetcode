class Solution {
public:
    int maximizeSquareArea(int a, int b, vector<int>& h, vector<int>& v) {
        unordered_map<int, int> m;
        h.push_back(1);
        h.push_back(a);
        sort(h.begin(), h.end());
        for (int i=0; i!=h.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                m[h[i]-h[j]]=1;
            }
        }
        int ans=-1, t;
        v.push_back(1);
        v.push_back(b);
        sort(v.begin(), v.end());
        for (int i=0; i!=v.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                t=v[i]-v[j];
                if (m[t]==1)
                {
                    m[t]=2;
                    ans=max(ans, t);
                }
            }
        }
        if (ans==-1) return ans;
        else return (long long)ans*ans%1000000007;
    }
};