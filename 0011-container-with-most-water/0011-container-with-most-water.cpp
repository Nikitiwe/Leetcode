class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, ans=0, loc=0;
        while (l<r)
        {
            loc=min(height[l], height[r])*(r-l);
            if (loc>ans) ans=loc;
            if (height[l]<height[r]) l++;
            else r--;
        }
        return ans;
    }
};