class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> t=nums;
        sort(t.begin(), t.end());
        int l=0, r=t.size()-1;
        while (l<t.size()&&nums[l]==t[l]) l++;
        while (r>=0&&nums[r]==t[r]) r--;
        if (r-l+1<=0) return 0;
        else return r-l+1;
    }
};