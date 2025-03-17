class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> q;
        for (int i=0; i!=nums.size(); i++) q.insert(nums[i]);
        int ans=0, ma=-1000, c=0;
        for (auto i=q.begin(); i!=q.end(); i++)
        {
            if (*i >= 0)
            {
                ans+=*i;
                c++;
            }
            if (*i < 0) ma = max(ma, *i);
        }
        if (c>0) return ans;
        else return ma;
    }
};