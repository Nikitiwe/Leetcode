class Solution {
public:
    vector<int> decrypt(vector<int>& c, int k) {
        vector<int> ans(c.size(), 0);
        if (k==0) for (int i=0; i!=c.size(); i++) c[i]=0;
        else if (k>0) while (k>0)
        {
            for (int i=0; i!=c.size(); i++)
            {
                ans[i]+=c[(i+k)%c.size()];
            }
            k--;
        }
        else while (k<0)
        {
            for (int i=0; i!=c.size(); i++)
            {
                ans[i]+=c[(i+k+c.size())%c.size()];
            }
            k++;
        }
        return ans;
    }
};