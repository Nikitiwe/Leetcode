class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        if (nums.size()==1) return 0;
        int count=1, ans=0;
        sort(nums.begin(), nums.end());
        for (int i=1; i!=nums.size(); i++)
        {
            if (nums[i]==nums[i-1]) {count++; if (i==nums.size()-1) ans=ans+count*(count-1)/2;}
            else {ans=ans+count*(count-1)/2; count=1;}
        }
        return ans;
    }
};