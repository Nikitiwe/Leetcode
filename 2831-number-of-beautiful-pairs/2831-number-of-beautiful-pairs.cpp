class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            int t=1;
            while (t*10<=nums[i]) t*=10;
            nums[i]/=t;
            for (int j=i+1; j<nums.size(); j++)
            {
                if (gcd(nums[i], nums[j]%10)==1) ans++;
            }
        }
        return ans;
    }
};