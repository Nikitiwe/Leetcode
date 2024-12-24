class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> m;
        int l=-2000000000;
        for (int i=0; i!=nums.size(); i++)
        {
            l=max(nums[i]-k, l);
            while (m.count(l)>0) l++;
            if (l<=nums[i]+k) m.insert(l);
        }
        return m.size();
    }
};