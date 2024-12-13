class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s=nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1]+1==nums[i]) s+=nums[i];
            else break;
        }
        unordered_set<int> m(nums.begin(), nums.end());
        for (int i=s; i<10000; i++)
        {
            if (m.count(i)==0) return i;
        }
        return -1;
    }
};