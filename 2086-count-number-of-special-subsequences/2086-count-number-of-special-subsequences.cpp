class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        long a=0, b=0, c=0;
        if (nums[0]==0) a++;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]==0)
            {
                a*=2;
                a++;
                a%=1000000007;
            }
            else if (nums[i]==1)
            {
                b*=2;
                b+=a;
                b%=1000000007;
            }
            else
            {
                c*=2;
                c+=b;
                c%=1000000007;
            }
        }
        return c;
    }
};