class Solution {
public:
    int countPairs(vector<int>& nums) {
        long long ans=0, k=1;
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++) m[nums[i]]++;
        for (int j=1; j<=22; j++)
        {
            for (int i=0; i!=nums.size(); i++)
            {
                if (m.count(k-nums[i])>0)
                {
                    if (k-nums[i]!=nums[i])
                    {
                        ans+=m[k-nums[i]];
                    }
                    else
                    {
                        ans+=(long long)(m[k-nums[i]]-1);
                    }
                }
            }
            k*=2;
        }
        return (ans/2)%1000000007;
    }
};