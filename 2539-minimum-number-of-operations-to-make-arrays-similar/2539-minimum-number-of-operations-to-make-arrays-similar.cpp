class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& t) {
        vector<int> n0, n1, t0, t1;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]%2==0) n0.push_back(nums[i]);
            else n1.push_back(nums[i]);
        }
        for (int i=0; i!=t.size(); i++)
        {
            if (t[i]%2==0) t0.push_back(t[i]);
            else t1.push_back(t[i]);
        }
        sort(n0.begin(), n0.end());
        sort(n1.begin(), n1.end());
        sort(t0.begin(), t0.end());
        sort(t1.begin(), t1.end());
        long ans=0;
        for (int i=0; i!=n0.size(); i++)
        {
            ans+=abs(n0[i]-t0[i]);
        }
        for (int i=0; i!=n1.size(); i++)
        {
            ans+=abs(n1[i]-t1[i]);
        }
        return ans/4;
    }
};