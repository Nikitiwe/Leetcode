class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        vector<int> n, p;
        long long ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]<0) n.push_back(nums[i]);
            else if (nums[i]>0) p.push_back(nums[i]);
        }
        if (n.size()%2==0&&n.size()>0)
        {
            ans=1;
            for (int i=0; i!=n.size(); i++) ans*=n[i];
        }
        else if (n.size()>1)
        {
            ans=1;
            sort(n.begin(), n.end());
            for (int i=0; i<n.size()-1; i++) ans*=n[i];
        }
        if (p.size()>0)
        {
            if (ans==0) ans=1;
            for (int i=0; i!=p.size(); i++) ans*=p[i];
        }
        return ans;
    }
};