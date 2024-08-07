class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int> (colsum.size(), 0));
        for (int i=0; i!=colsum.size(); i++)
        {
            if (colsum[i]==2)
            {
                ans[0][i]=1;
                upper--;
                ans[1][i]=1;
                lower--;
            }
        }
        if (upper<0) return {};
        for (int i=0; i!=colsum.size(); i++)
        {
            if (colsum[i]==1)
            {
                if (upper>0)
                {
                    ans[0][i]=1;
                    upper--;
                }
                else
                {
                    ans[1][i]=1;
                    lower--;
                }
            }
        }
        if (lower!=0) return {};
        else return ans;
    }
};