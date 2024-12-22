class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum=0, ans=-2000;
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            m[nums[i]]++;
        }
        for (int i=0; i!=nums.size(); i++)
        {
            int t=sum-nums[i];
            if (t%2==0&&m.count(t/2)>0)
            {
                if (t/2!=nums[i]) ans=max(ans, nums[i]);
                else if (m[t/2]>1) ans=max(ans, nums[i]);
            }
        }
        return ans;
    }
};