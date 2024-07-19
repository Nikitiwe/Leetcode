class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int a, f;
        for (int i=0; i!=matrix.size(); i++)
        {
            f=1;
            a=distance(matrix[i].begin(), min_element(matrix[i].begin(), matrix[i].end()));
            for (int j=0; j!=matrix.size(); j++)
            {
                if (matrix[j][a]>matrix[i][a]) {f=0; break;}
            }
            if (f==1) ans.push_back(matrix[i][a]);
        }
        return ans;
    }
};