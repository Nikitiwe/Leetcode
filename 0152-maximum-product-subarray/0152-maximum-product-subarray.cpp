class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long ans=nums[0], fn=1, temp=1;
        int id=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==0)
            {
                fn=1;
                temp=1;
                ans=max(ans, (long)0);
            }
            else
            {
                temp*=nums[i];
                if (fn==1&&temp<0)
                {
                    fn=temp;
                    id=i;
                }
                if (temp>0) ans=max(ans, temp);
                else if (i!=id) ans=max(ans, temp/fn);
            }
        }
        return ans;
    }
};