class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        nums.push_back(nums[0]);
        int d=0, t=0;
        for (int i=0; i!=nums.size()-1; i++)
        {
            if (nums[i]>nums[i+1])
            {
                d++;
                t=i;
            }
        }
        if (d>1) return -1;
        else return nums.size()-t-2;
    }
};