class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& m) {
        vector<int> ans(2, 0);
        for (int i=0; i!=m.size(); i++)
        {
            int sum=0;
            for (int j=0; j!=m[0].size(); j++)
            {
                sum+=m[i][j];
            }
            if (sum>ans[1])
            {
                ans[0]=i;
                ans[1]=sum;
            }
        }
        return ans;
    }
};