class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long, int> m;
        int ans=-1;
        for (int i=0; i!=nums.size(); i++)
        {
            if (m.count(nums[i])>0) m[(long)nums[i]*nums[i]]=m[nums[i]]+1;
            else m[(long)nums[i]*nums[i]]=1;
            if (m[(long)nums[i]*nums[i]]>1) ans=max(ans, m[(long)nums[i]*nums[i]]);
        }
        return ans;
    }
};