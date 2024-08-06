class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> arr(1000002, 0);
        int temp=0, ans;
        for(int i=0; i!=intervals.size(); i++)
        {
            arr[intervals[i][0]]++;
            arr[intervals[i][1]+1]--;
            temp=max(temp, intervals[i][1]);
        }
        ans=arr[0];
        for(int i=1; i<=temp+1; i++)
        {
            arr[i]+=arr[i-1];
            ans=max(ans, arr[i]);
        }
        return ans;
    }
};