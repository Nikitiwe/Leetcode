class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> m;
        for (int i=0; i!=nums.size(); i++)
        {
            nums[i]-=i;
            m[nums[i]]++;
        }
        long long ans=0;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            ans+=(i->second)*(nums.size()-i->second);
        }
        return ans/2;
    }
};