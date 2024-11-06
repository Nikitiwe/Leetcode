class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> k, m;
        int l=0, ma=nums[0], mi=ma, prev=0;
        int t=nums[0];
        int s=0;
        while (t>0)
        {
            prev+=t%2;
            t/=2;
        }
        for (int i=1; i<nums.size(); i++)
        {
            t=nums[i];
            s=0;
            while (t>0)
            {
                s+=t%2;
                t/=2;
            }
            if (prev==s)
            {
                ma=max(nums[i], ma);
                mi=min(nums[i], mi);
            }
            else
            {
                k.push_back(ma);
                m.push_back(mi);
                l=i;
                prev=s;
                ma=nums[i];
                mi=nums[i];
            }
        }
        k.push_back(ma);
        m.push_back(mi);
        for (int i=0; i<k.size()-1; i++) if (k[i]>m[i+1]) return 0;
        return 1;
    }
};