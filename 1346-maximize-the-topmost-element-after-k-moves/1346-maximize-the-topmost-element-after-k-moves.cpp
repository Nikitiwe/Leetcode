class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (k==0) return nums[0];
        if (k%2==1&&nums.size()==1) return -1;
        if (k==1) return nums[1];
        int id=0, ma=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (k==1)
            {
                id=i;
                break;
            }
            else
            {
                ma=max(ma, nums[i]);
            }
            k--;
        }
        if (id<nums.size()-1) return max(ma, nums[id+1]);
        else return ma;
    }
};