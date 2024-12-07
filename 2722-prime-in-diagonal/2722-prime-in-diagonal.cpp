class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            int t=nums[i][i], c=0, g=sqrt(t), j=2;
            while (j<=g)
            {
                if (t%j==0)
                {
                    t/=j;
                    c++;
                    if (t>1) {c++; break;}
                }
                else j++;
            }
            if (c<=1) ans=max(ans, nums[i][i]);
        }
        for (int i=0; i!=nums.size(); i++)
        {
            int t=nums[nums.size()-1-i][i], c=0, g=sqrt(t), j=2;
            while (j<=g)
            {
                if (t%j==0)
                {
                    t/=j;
                    c++;
                    if (t>1) {c++; break;}
                }
                else j++;
            }
            if (c<=1) ans=max(ans, nums[nums.size()-1-i][i]);
        }
        if (ans>1) return ans;
        else return 0;
    }
};