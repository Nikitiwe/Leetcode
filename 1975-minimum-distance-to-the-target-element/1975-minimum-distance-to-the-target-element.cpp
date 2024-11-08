class Solution {
public:
    int getMinDistance(vector<int>& nums, int t, int s) {
        if (nums[s]==t) return 0;
        for (int i=1; i<nums.size(); i++)
        {
            if (s>=i&&nums[s-i]==t) return i;
            if (s+i<nums.size()&&nums[s+i]==t) return i;
        }
        return -1;
    }
};