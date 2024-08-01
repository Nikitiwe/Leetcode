class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size()-1; i++)
        {
            if ((i+ans)%2==0&&nums[i]==nums[i+1]) ans++;
        }
        if ((nums.size()-ans)%2==1) ans++;
        return ans;
    }
};