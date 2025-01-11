class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& nums) {
        unordered_map<int, int> m;
        int ma=0;
        for (int i=0; i<nums.size()-1; i++)
        {
            if (nums[i]<nums[i+1])
            {
                for (int j=nums[i]; j<nums[i+1]; j++)
                {
                    m[j]++;
                    ma=max(ma, m[j]);
                }
            }
            else
            {
                for (int j=nums[i]; j<=n; j++)
                {
                    m[j]++;
                    ma=max(ma, m[j]);
                }
                for (int j=1; j<nums[i+1]; j++)
                {
                    m[j]++;
                    ma=max(ma, m[j]);
                }
            }
        }
        m[nums.back()]++;
        ma=max(ma, m[nums.back()]);
        vector<int> ans;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==ma) ans.push_back(i->first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};