class Solution {
public:
    int mostFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int id=0;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1]==k)
            {
                m[nums[i]]++;
                if (m[nums[i]]>m[id]) id=nums[i];
            }
        }
        return id;
    }
};