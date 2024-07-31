class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> lmax(nums.size(), 0), rmin(nums.size(), 0);
        lmax[0]=nums[0];
        for (int i=1; i!=nums.size(); i++)
        {
            lmax[i]=max(lmax[i-1], nums[i]);
        }
        rmin[nums.size()-1]=nums[nums.size()-1];
        for (int i=nums.size()-2; i>=0; i--)
        {
            rmin[i]=min(rmin[i+1], nums[i]);
        }
        for (int i=0; i!=nums.size()-1; i++)
        {
            if (lmax[i]<=rmin[i+1]) return i+1;
        }
        return 0;
    }
};