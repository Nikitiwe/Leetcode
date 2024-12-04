class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hb, vector<int>& vb) {
        unordered_set<int> v;
        sort(hb.begin(), hb.end());
        sort(vb.begin(), vb.end());
        vb.push_back(m+4);
        hb.push_back(n+4);
        int ans=2, p=vb[0], c=1;
        for (int i=1; i<vb.size(); i++)
        {
            if (vb[i]==p+1)
            {
                p=vb[i];
                c++;
                v.insert(c+1);
            }
            else
            {
                p=vb[i];
                v.insert(c+1);
                c=1;
            }
        }
        p=hb[0]; c=1;
        for (int i=1; i<hb.size(); i++)
        {
            if (hb[i]==p+1)
            {
                p=hb[i];
                c++;
                if (v.count(c+1)>0) ans=max(ans, c+1);
            }
            else
            {
                p=hb[i];
                if (v.count(c+1)>0) ans=max(ans, c+1);
                c=1;
            }
        }
        return ans*ans;
    }
};