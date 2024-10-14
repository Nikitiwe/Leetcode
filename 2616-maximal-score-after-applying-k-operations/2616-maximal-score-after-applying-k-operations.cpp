class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> p;
        for (int i=0; i!=nums.size(); i++)
        {
            p.push(nums[i]);
        }
        long long ans=0;
        for (int i=1; i<=k; i++)
        {
            int t=p.top();
            p.pop();
            ans+=t;
            p.push((t+2)/3);
        }
        return ans;
    }
};