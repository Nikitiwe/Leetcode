class Solution {
public:
    int distanceBetweenBusStops(vector<int>& nums, int s, int d) {
        int t=accumulate(nums.begin(), nums.end(), 0), ans=0;
        if (s>d) swap(s, d);
        for (int i=s; i<d; i++) ans+=nums[i];
        return min(ans, t-ans);

    }
};