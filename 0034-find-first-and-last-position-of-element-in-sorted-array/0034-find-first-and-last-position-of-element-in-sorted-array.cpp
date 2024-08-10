class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        vector<int> ans(2, -1);
        int l=0, r=nums.size()-1, m;
        while (l<=r)
        {
            m=(l+r)/2;
            if (nums[m]==tar&&(m==0||nums[m-1]<tar)) {ans[0]=m; break;}
            else if (nums[m]>=tar) {r=m-1; if (r<0) return {-1, -1};}
            else if (nums[m]<tar) {l=m+1; if (l>=nums.size()) return {-1, -1};}
        }
        l=0; r=nums.size()-1;
        while (l<=r)
        {
            m=(l+r)/2;
            if (nums[m]==tar&&(m==nums.size()-1||nums[m+1]>tar)) {ans[1]=m; break;}
            else if (nums[m]>tar) {r=m-1; if (r<0) return {-1, -1};}
            else if (nums[m]<=tar) {l=m+1; if (l>=nums.size()) return {-1, -1};}
        }
        return ans;
    }
};