class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++) m[-nums[i]]=i;
        vector<vector<int>> ans;
        unordered_set<long> n;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]>0) break;
            if (i>0&&nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<nums.size(); j++)
            {
                if (nums[j]+nums[i]>0) break;
                if (m.count(nums[i]+nums[j])>0&&m[nums[i]+nums[j]]>j)
                {
                    long a=nums[i];
                    long b=nums[j];
                    n.insert((a+100000)*1000000+(b+100000));
                }
            }
        }
        for (auto i=n.begin(); i!=n.end(); i++)
        {
            int a=(int)(*i/1000000-100000);
            int b=(int)(*i%1000000-100000);
            ans.push_back({a, b, 0-a-b});
        }
        return ans;
    }
};