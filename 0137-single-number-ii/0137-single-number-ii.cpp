class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> ans(20, 0), ansm(20, 0);
        int j;
        for (int i=0; i!=nums.size(); i++)
        {
            j=0;
            if (nums[i]>0) while (nums[i]>0)
            {
                ans[j]=(ans[j]+nums[i]%3)%3;
                nums[i]=nums[i]/3;
                j++;
            }
            else while (nums[i]<0)
            {
                ansm[j]=(ansm[j]+nums[i]%3)%3;
                nums[i]=nums[i]/3;
                j++;
            }
        }
        j=0;
        for (int i=19; i>=0; i--)
        {
            j=j*3+ans[i];
        }
        if (ans[0]+ans[1]+ans[2]+ans[3]+ans[4]+ans[5]+ans[6]+ans[7]+ans[8]+ans[9]+ans[10]
        +ans[11]+ans[12]+ans[13]+ans[14]+ans[15]+ans[16]!=0)
        { return j; }
        else
        {
        j=0;
        for (int i=19; i>=0; i--)
        {
            j=j*3+ansm[i];
        }
        }
        return j;
    }
};