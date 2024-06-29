class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool temp;
        if (nums[0]==1) return 1;
        else for (int i=2; i<=nums[0]; i++)
        {
            if (nums[0]%i==0)
            {
                temp=0;
                for (int j=1; j!=nums.size(); j++)
                {
                    if (nums[j]%i!=0) temp=1;
                }
                if (temp==0) return 0;
            }
        }
        return 1;
    }
};