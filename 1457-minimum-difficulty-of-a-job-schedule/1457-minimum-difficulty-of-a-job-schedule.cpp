class Solution {
public:
    int minDifficulty(vector<int>& nums, int d) {
        if (nums.size()<d) return -1;
        vector<vector<int>> a(d, vector<int> (nums.size(), 10001)), b(nums.size(), vector<int> (nums.size(), 0));
        
        for (int i=0; i<b.size(); i++) // b[i][j] это сложность отрезка [i, j]
        {
            b[i][i]=nums[i];
            for (int j=i+1; j<b[i].size(); j++)
            {
                b[i][j]=max(b[i][j-1], nums[j]);
            }
        }

        for (int i=0; i<nums.size(); i++) // a[k][j] это ответ на k+1 день на j работу
        {
            a[0][i]=b[0][i];
        }
        for (int k=1; k<d; k++)
        {
            a[k][k]=a[k-1][k-1]+nums[k];
            for (int i=k; i<nums.size(); i++) // i это переход, то есть i работа делается уже в следующий день
            {
                for (int j=i; j<nums.size(); j++)
                {
                    a[k][j]=min(a[k][j], a[k-1][i-1]+b[i][j]);
                }
            }
        }
        return a[d-1][nums.size()-1];
    }
};