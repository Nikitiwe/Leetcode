class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            int sum=0, id=i;
            while (id>0)
            {
                if (id%2==1) sum++;
                id/=2;
            }
            if (sum==k) ans+=nums[i];
        }
        return ans;
    }
};