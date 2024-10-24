class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans=0, n=nums.size();
        unordered_map<int, int> m;
        for (int i=0; i!=n; i++) m[nums[i]]++;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            int t=i->first, h=i->second;
            for (auto j=m.begin(); j!=m.end(); j++)
            {
                if (j->first!=t)
                {
                    ans+=h*j->second*(n-h-j->second);
                }
            }
        }
        return ans/6;
    }
};