class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k==0) return 0;
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            if (m.count(nums[i])>0)
            {
                if (i-m[nums[i]]<=k) return 1;
            }
            m[nums[i]]=i;
        }
        return 0;
    }
};