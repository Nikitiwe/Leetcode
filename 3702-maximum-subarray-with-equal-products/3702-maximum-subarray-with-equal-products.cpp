class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            int g=nums[i], l=nums[i], p=nums[i];
            if (g*l==p) ans=max(ans, 1);
            for (int j=i+1; j<nums.size(); j++)
            {
                g=gcd(g, nums[j]);
                l=lcm(l, nums[j]);
                p*=nums[j];
                if (g*l==p) ans=max(ans, j-i+1);
                if (p>100000000) break;
            }
        }
        return ans;
    }
};