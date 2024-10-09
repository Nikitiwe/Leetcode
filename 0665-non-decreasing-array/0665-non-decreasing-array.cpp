class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size()<=2) return 1;
        int t=0, temp=-100000;
        for (int i=0; i<nums.size()-1; i++)
        {
            if (nums[i]>nums[i+1]&&nums[i+1]>=temp)
            {
                t++;
            }
            else
            {
                temp=max(temp, nums[i]);
                if (temp>nums[i+1]) t++;
            }
            if (t>1) return 0;
        }
        return 1;
    }
};