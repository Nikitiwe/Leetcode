class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n, 0);
        for (int i=0; i!=k-1; i++)
        {
            if (i%2==0) ans[i]=i/2+1;
            else ans[i]=n-(i+1)/2+1;
        }
        if (k%2==0)
        {
            for (int i=k-1; i!=n; i++)
            {
                ans[i]=n-i+k/2;
            }
        }
        else
        {
            for (int i=k-1; i!=n; i++)
            {
                ans[i]=i-k/2+1;
            }
        }
        return ans;
    }
};