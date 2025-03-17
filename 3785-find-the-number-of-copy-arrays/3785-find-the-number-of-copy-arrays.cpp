class Solution {
public:
    int countArrays(vector<int>& nums, vector<vector<int>>& b) {
        int ma = 2000000000, mi = -ma;
        for (int i=0; i!=nums.size(); i++)
        {
            ma = min(ma, b[i][1]-(nums[i]-nums[0]));
            mi = max(mi, b[i][0]-(nums[i]-nums[0]));
        }
        if (ma - mi + 1>= 0) return ma - mi + 1;
        else return 0;
    }
};