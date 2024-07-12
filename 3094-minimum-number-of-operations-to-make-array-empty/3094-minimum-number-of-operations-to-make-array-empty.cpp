class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0, temp=1;
        for (int i=1; i!=nums.size(); i++)
        {
            if (nums[i]==nums[i-1]) temp++;
            else
            {
                if (temp==1) return -1;
                ans+=temp/3;
                if (temp%3!=0) ans+=1;
                temp=1;
            }
        }
        if (temp==1) return -1;
        ans+=temp/3;
        if (temp%3!=0) ans+=1;
        temp=1;
        return ans;
    }
};