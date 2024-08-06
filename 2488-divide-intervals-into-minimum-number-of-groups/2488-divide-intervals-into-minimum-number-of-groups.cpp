class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int l=intervals[0][0], r=0, ans;
        for(int i=0; i!=intervals.size(); i++)
        {
            l=min(l, intervals[i][0]);
            r=max(r, intervals[i][1]);
        }
        vector<int> arr(r-l+2, 0);
        for(int i=0; i!=intervals.size(); i++)
        {
            arr[intervals[i][0]-l]++;
            arr[intervals[i][1]+1-l]--;
        }
        ans=arr[0];
        for(int i=1; i<=r-l+1; i++)
        {
            arr[i]+=arr[i-1];
            ans=max(ans, arr[i]);
        }
        return ans;
    }
};