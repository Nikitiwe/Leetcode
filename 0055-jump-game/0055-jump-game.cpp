class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==1) return 1;
        nums[nums.size()-1]=nums.size();
        for (int i=nums.size()-2; i>=0; i--)
        {
            for (int j=nums[i]; j>=0; j--)
            {
                if (i+j>nums.size()-1) j=nums.size()-1-i;
                if (nums[i+j]==nums.size()) {nums[i]=nums.size(); break;}
            }
        }
        if (nums[0]==nums.size()) return 1;
        else return 0;
    }
};