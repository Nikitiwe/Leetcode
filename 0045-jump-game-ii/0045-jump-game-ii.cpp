class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()==1) return 0;
        int m, temp;
        nums[nums.size()-1]=0;
        for (int i=nums.size()-2; i>=0; i--)
        {
            m=99999;
            temp=min((int)nums.size()-1-i, nums[i]);
            for (int j=1; j<=temp; j++)
            {
                m=min(m, nums[i+j]);
            }
            nums[i]=m+1;
        }
        return nums[0];
    }
}; // код наследован частично с Jump Game