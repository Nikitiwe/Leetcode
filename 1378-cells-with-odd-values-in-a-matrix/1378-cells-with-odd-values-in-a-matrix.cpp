class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& nums) {
        int oro=0, oc=0;
        vector<int> row(m, 0), col(n, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            row[nums[i][0]]=(1-row[nums[i][0]]);
            col[nums[i][1]]=(1-col[nums[i][1]]);
        }
        for (int i=0; i!=m; i++)
        {
            if (row[i]==1) oro++;
        }
        for (int i=0; i!=n; i++)
        {
            if (col[i]==1) oc++;
        }
        return oro*(n-oc)+oc*(m-oro);
    }
};