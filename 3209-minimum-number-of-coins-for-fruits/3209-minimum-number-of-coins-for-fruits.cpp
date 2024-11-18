class Solution {
public:
    int minimumCoins(vector<int>& p) {
        if (p.size()==1) return p[0];
        vector<int> ans(p.size()+1, 1000000000);
        ans.back()=p.back();
        for (int i=ans.size()-2; i>=1; i--)
        {
            int t=ans[i+1], l=i+2;
            while (l<=i*2+1)
            {
                if (l==ans.size())
                {
                    t=0;
                    break;
                }
                else
                {
                    t=min(t, ans[l]);
                    l++;
                }
            }
            ans[i]=p[i-1]+t;
        }
        return ans[1];
    }
};