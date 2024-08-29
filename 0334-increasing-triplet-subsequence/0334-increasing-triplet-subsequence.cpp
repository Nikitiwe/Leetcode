class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3) return 0;
        int t1=nums[0], t2;
        bool is2=0;
        for (int i=1; i!=nums.size(); i++)
        {
            if (is2==0)
            {
                if (nums[i]<t1)
                {
                    t1=nums[i];
                }
                else if (nums[i]>t1)
                {
                    is2=1;
                    t2=nums[i];
                }
            }
            else
            {
                if (nums[i]>t2) return 1;
                else if (nums[i]<t1)
                {
                    t1=nums[i];
                }
                else if (nums[i]>t1&&nums[i]<t2)
                {
                    t2=nums[i];
                }
            }
        }
        return 0;
    }
};