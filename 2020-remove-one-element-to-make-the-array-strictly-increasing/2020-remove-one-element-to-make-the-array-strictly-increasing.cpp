class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int c=0;
        for (int i=0; i<nums.size(); i++)
        {
            c=0;
            for (int j=0; j<nums.size()-1; j++)
            {
                if (j!=i&&j+1!=i)
                {
                    if (nums[j]>=nums[j+1])
                    {
                        c++;
                        break;
                    }
                }
                else if (j+1==i&&j+2<nums.size())
                {
                    if (nums[j]>=nums[j+2])
                    {
                        c++;
                        break;
                    }
                }
            }
            if (c==0) return 1;
        }
        return 0;
    }
};