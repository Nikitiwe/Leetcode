class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> sumy(nums.size(), 0), sumn(nums.size(), 0);
        sumy[0]=nums[0];
        for (int i=1; i!=nums.size(); i++)
        {
            sumy[i]=sumn[i-1]+nums[i];
            sumn[i]=max(sumy[i-1], sumn[i-1]);
        }
        return max(sumy[nums.size()-1], sumn[nums.size()-1]);
    }
};