class Solution {
public:
    long long maxScore(vector<int>& nums) {
        if (nums.size()==1) return nums[0]*nums[0];
        vector<long long> ll(nums.size(), 0), lg=ll, rl=ll, rg=ll;
        long long l=nums[0], g=nums[0];
        for (int i=0; i!=nums.size(); i++)
        {
            l=gcd(l, nums[i]);
            g=lcm(g, nums[i]);
            ll[i]=l;
            lg[i]=g;
        }
        long long ans=ll.back()*lg.back();
        l=nums[nums.size()-1]; g=nums[nums.size()-1];
        for (int i=nums.size()-1; i>=0; i--)
        {
            l=gcd(l, nums[i]);
            g=lcm(g, nums[i]);
            rl[i]=l;
            rg[i]=g;
        }
        ans=max(ans, rl[1]*rg[1]);
        ans=max(ans, ll[nums.size()-2]*lg[nums.size()-2]);

        for (int i=1; i<nums.size()-1; i++)
        {
            ans=max(ans, gcd(ll[i-1], rl[i+1])*lcm(lg[i-1], rg[i+1]));
        }
        return ans;
    }
};