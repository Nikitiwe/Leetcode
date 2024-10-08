class Solution {
public:
    int maximizeSquareArea(int a, int b, vector<int>& h, vector<int>& v) {
        unordered_set<int> m, n;
        h.push_back(1);
        h.push_back(a);
        for (int i=0; i!=h.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                m.insert(abs(h[i]-h[j]));
            }
        }
        v.push_back(1);
        v.push_back(b);
        for (int i=0; i!=v.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                n.insert(abs(v[i]-v[j]));
            }
        }
        int ans=-1;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (n.count(*i)>0) ans=max(ans, *i);
        }
        if (ans==-1) return ans;
        else return (long long)ans*ans%1000000007;
    }
};