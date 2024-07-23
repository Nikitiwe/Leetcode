class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sum=0, temp=0, m, n=nums.size();
        for (int i=0; i!=n; i++)
        {
            sum+=nums[i];
        }
        for (int i=0; i!=sum; i++)
        {
            if (nums[i]==0) temp++;
        }
        m=temp;
        for (int i=0; i!=n; i++)
        {
            if (nums[i]==0) temp--;
            if (nums[(i+sum)%n]==0) temp++;
            m=min(m, temp);
        }
        return m;
    }
};