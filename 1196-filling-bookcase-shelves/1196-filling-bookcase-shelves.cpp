class Solution {
public:
    int minHeightShelves(vector<vector<int>>& b, int s) {
        vector<int> ans(b.size()+1, 2000000);
        ans[0]=0;
        for (int i=0; i!=b.size(); i++)
        {
            int h=0, w=0, j=0;
            while (i-j>=0)
            {
                h=max(h, b[i-j][1]);
                w+=b[i-j][0];
                if (w>s) break;
                else ans[i+1]=min(ans[i+1], ans[i-j]+h);
                j++;
            }
        }
        return ans[b.size()];
    }
};