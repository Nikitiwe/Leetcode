class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int a=0, b=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==5) a++;
            else if (nums[i]==10)
            {
                b++;
                a--;
                if (a<0) return 0;
            }
            else if (nums[i]==20)
            {
                if (b>0)
                {
                    b--;
                    a--;
                }
                else a-=3;
                if (a<0) return 0;
            }
        }
        return 1;
    }
};