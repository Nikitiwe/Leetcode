class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<vector<int>> t;
        vector<int> sum;
        t.push_back({});
        sum.push_back(0);
        for (int i=0; i!=nums.size(); i++)
        {
            int count = t.size();
            for (int j=0; j<count; j++)
            {
                vector<int> temp = t[j];
                int s = sum[j];
                while (s + nums[i] <= k)
                {
                    temp.push_back(nums[i]);
                    s += nums[i];
                    if (s == k) ans.push_back(temp);
                    else
                    {
                        t.push_back(temp);
                        sum.push_back(s);
                    }
                }
            }
        }
        return ans;
    }
};